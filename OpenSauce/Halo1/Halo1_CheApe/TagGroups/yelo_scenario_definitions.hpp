/*
    Yelo: Open Sauce SDK
		Halo 1 (Editing Kit) Edition
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
#pragma once

namespace Yelo
{
	namespace TagGroups
	{
		struct scenario;

		// Removes Yelo-related data so that the scenario may be opened with no conflicts in the stock HEK
		void YeloCleanseScenario(scenario* scnr);

		// Returns the tag index of the scenario's [project_yellow] tag or datum_index::null if there isn't one or it fails to load
		datum_index YeloPrepareDefinitions(cstring scenario_name, const bool for_build_cache);


		void ScenarioYeloLoadHookInitialize();
		void ScenarioYeloLoadHookDispose();
	};
};