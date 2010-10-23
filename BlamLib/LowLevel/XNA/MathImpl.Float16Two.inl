/*
    BlamLib: .NET SDK for the Blam Engine

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

#include <boost/preprocessor/iteration/iterate.hpp>

#if !BOOST_PP_IS_ITERATING

	#if defined(__XNA_MATH_IMPL_CODE_INCLUDE_ID)
		#define BOOST_PP_ITERATION_PARAMS_1 (3, (__XNA_MATH_IMPL_CODE_INCLUDE_ID, __XNA_MATH_IMPL_CODE_INCLUDE_ID, "XNA/MathImpl.Float16Two.inl"))
		??=include BOOST_PP_ITERATE()
		#undef __XNA_MATH_IMPL_CODE_INCLUDE_ID
	#endif


	//////////////////////////////////////////////////////////////////////////
	// C++/clr header code
	#elif BOOST_PP_ITERATION() == __XNA_MATH_IMPL_CODE_CLR_HPP

		static LowLevel::Math::real_quaternion ConvertFloat16Two(mcpp_ushort value_x, mcpp_ushort value_y);

		static void ConvertFloat16Two(LowLevel::Math::real_quaternion input, mcpp_out(mcpp_ushort) value_x, mcpp_out(mcpp_ushort) value_y);



	//////////////////////////////////////////////////////////////////////////
	// C++/clr source code
	#elif BOOST_PP_ITERATION() == __XNA_MATH_IMPL_CODE_CLR_CPP

		LowLevel::Math::real_quaternion Math::ConvertFloat16Two(mcpp_ushort value_x, mcpp_ushort value_y)
		{
			LowLevel::Math::real_quaternion ret = LowLevel::Math::real_quaternion();

			pin_ptr<mcpp_real> output = &ret.Vector.I;
			::Internal::ConvertFloat16Two(value_x, value_y, output);

			return ret;
		}

		void Math::ConvertFloat16Two(LowLevel::Math::real_quaternion input, mcpp_out(mcpp_ushort) value_x, mcpp_out(mcpp_ushort) value_y)
		{
			pin_ptr<mcpp_real> vec = &input.Vector.I;
			mcpp_ushort v_x, v_y;
			::Internal::StoreFloat16Two(v_x, v_y, vec);
			value_x = v_x;	value_y = v_y;
		}



	//////////////////////////////////////////////////////////////////////////
	// Native C++ code
	#elif BOOST_PP_ITERATION() == __XNA_MATH_IMPL_CODE_CPP

		static void ConvertFloat16Two(cpp_ushort value_x, cpp_ushort value_y, cpp_real* output)
		{
			XMHALF2 xm_type; xm_type.x = value_x; xm_type.y = value_y;

			XMVECTOR vec = ::XMLoadHalf2(&xm_type);

#if defined(_XM_SSE_INTRINSICS_) && !defined(_XM_NO_INTRINSICS_)
			_mm_storeu_ps(output, vec);
#else
			output[0] = vec.v[0];	output[1] = vec.v[1];
#endif
		}

		static void StoreFloat16Two(cpp_ushort& value_x, cpp_ushort& value_y, cpp_real* input)
		{
			XMVECTOR vec;
#if defined(_XM_SSE_INTRINSICS_) && !defined(_XM_NO_INTRINSICS_)
			vec = _mm_set_ps(input[0], input[1], 0, 0);
#else
			vec.v[0] = input[0];	vec.v[1] = input[1];
#endif

			XMHALF2 xm_type;
			::XMStoreHalf2(&xm_type, vec);
			value_x = xm_type.x;	value_y = xm_type.y;
		}

#else
#endif