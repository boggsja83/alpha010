#pragma once

#include "ALL.h"
#include "InputContext.h"

namespace ss
{
	typedef struct ICDtest1 : InputContextDef
	{
		//InputContext	IC_;
		//std::vector<InputContextValue> ICVvec_;

		ICDtest1()
		{
			IC_ = IC::TEST1;

			ICVvec_.push_back(ICV::TESTVAL5);
			ICVvec_.push_back(ICV::TESTVAL6);
		}
	} ICD_t1;
} // END	namespace ss
