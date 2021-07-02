#pragma once

#include "ALL.h"
#include "InputContext.h"

namespace ss
{
	typedef struct ICDengMenu : InputContextDef
	{
		//InputContext	IC_;
		//std::vector<InputContextValue> ICVvec_;

		ICDengMenu()
		{
			IC_ = IC::MENU;
			
			ICVvec_.push_back(ICV::MENU_SELECT);
			ICVvec_.push_back(ICV::MENU_UP);
			ICVvec_.push_back(ICV::MENU_DOWN);
			ICVvec_.push_back(ICV::MENU_NEXT);
			ICVvec_.push_back(ICV::MENU_PREV);
		}
	} ICD_em;
} // END	namespace ss
