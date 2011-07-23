/*
    Yelo: Open Sauce SDK
		Halo 1 (CE) Edition
    Copyright (C) 2005-2010  Kornner Studios (http://kornner.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "Common/Precompile.hpp"
#include "Common/DebugMemory.hpp"

#ifdef API_DEBUG_MEMORY

static unsigned int g_break_on_allocation = NONE;

void c_memory_tracker::AddBlock(void* pointer, size_t size)
{
	// increase the number of blocks and allocation index
	m_allocation_index++;

	if(g_break_on_allocation == m_allocation_index)
		while(true);

	m_block_count++;
	// reallocate the memory block array for the new size
	m_memory_blocks = (s_memory_block*)realloc(m_memory_blocks, sizeof(c_memory_tracker) * m_block_count);

	// set the last blocks values
	m_memory_blocks[m_block_count - 1].m_allocation_index = m_allocation_index;
	m_memory_blocks[m_block_count - 1].m_pointer = pointer;
	m_memory_blocks[m_block_count - 1].m_size = size;

	// update the current memory usage
	m_total_memory += size;
}
void c_memory_tracker::RemoveBlock(void* pointer)
{
	// return on a null pointer
	if(pointer == NULL)
		return;

	int index = -1;
	// find the memory block by pointer
	for(unsigned int i = 0; i < m_block_count; i++)
	{
		if(pointer == m_memory_blocks[i].m_pointer)
		{
			index = i;
			break;
		}
	}

	// something is very wrong if there is no memory block!
	if(index == -1)
		throw;

	// reduce the block count and update the total memory allocated
	m_block_count--;
	m_total_memory -= m_memory_blocks[index].m_size;

	// shift the blocks after the deleted block up to remove it
	for(unsigned int i = index; i < m_block_count; i++)
		m_memory_blocks[i] = m_memory_blocks[i + 1];

	// reallocate the memory block array to free up the last element
	m_memory_blocks = (s_memory_block*)realloc(m_memory_blocks, sizeof(c_memory_tracker) * m_block_count);
}
void c_memory_tracker::DumpAllocatedMemory()
{
	// create the memdump directory if it does not exist
	// could do with deleting the directory contents first if it does exists
	CreateDirectory("memdump", NULL);

	// create the memory allocations file
	FILE* memory_list;
	fopen_s(&memory_list, "memdump\\memdump.txt", "w");

	// write the allocations descriptions
	fputs("Halo1_CE OpenSauce allocated memory dump\n", memory_list);
	fputs("\n", memory_list);
	fprintf(memory_list, "Total allocations: %i\n", m_allocation_index);
	fprintf(memory_list, "Current allocations: %i\n", m_block_count);
	fprintf(memory_list, "Current memory usage: %i bytes\n", m_total_memory);

	// write the allocation information of each block and dump the memory to file
	for(unsigned int i = 0; i < m_block_count; i++)
	{
		// write information about the allocation
		fputs("\n", memory_list);
		fprintf(memory_list, "allocation index: %i\n", m_memory_blocks[i].m_allocation_index);
		fprintf(memory_list, "memory pointer: 0x%08X\n", m_memory_blocks[i].m_pointer);
		fprintf(memory_list, "allocation size: %i bytes\n", m_memory_blocks[i].m_size);

		// write the memory itself to file
		char dump_filename[MAX_PATH];
		sprintf_s(dump_filename, MAX_PATH, "memdump\\dump_index%i_size%i.bin", m_memory_blocks[i].m_allocation_index, m_memory_blocks[i].m_size);
		
		HANDLE memory_dump = CreateFile(dump_filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		
		DWORD bytes_written;
		BOOL success = WriteFile(memory_dump, m_memory_blocks[i].m_pointer, m_memory_blocks[i].m_size, &bytes_written, NULL);

		// something is wrong! currently unhandled
		if(!success || (bytes_written != m_memory_blocks[i].m_size))
			throw;

		FlushFileBuffers(memory_dump);
		CloseHandle(memory_dump);
	}
	fclose(memory_list);
}

void DumpAllocatedMemory()
{
	g_mem_tracker.DumpAllocatedMemory();
}

void* _cdecl operator new(size_t size)
{
	void* pointer = malloc(size);
	g_mem_tracker.AddBlock(pointer, size);
	return pointer;
}
void _cdecl operator delete(void* pointer)
{
	g_mem_tracker.RemoveBlock(pointer);
	free(pointer);
}
void* _cdecl operator new[](size_t size)
{
	void* pointer = malloc(size);
	g_mem_tracker.AddBlock(pointer, size);
	return pointer;
}
void _cdecl operator delete[](void* pointer)
{
	g_mem_tracker.RemoveBlock(pointer);
	free(pointer);
}
#endif