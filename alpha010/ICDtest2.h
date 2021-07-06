#pragma once

#include "ALL.h"
#include "InputContext.h"

namespace ss
{
	struct ICDtest2 : InputContextDef
	{
		ICDtest2()
		{
			IC_ = IC::TEST2;

			ICVvec_.push_back(ICV::TESTVAL1);
			ICVvec_.push_back(ICV::TESTVAL2);
			ICVvec_.push_back(ICV::TESTVAL3);
			ICVvec_.push_back(ICV::TESTVAL4);
		}
	};

	static ICDtest2 const ICD_t2;
} // END	namespace ss
