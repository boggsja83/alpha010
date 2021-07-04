#pragma once

#include "ALL.h"
#include "SDL.h"
#include <vector>

namespace ss
{
	typedef enum class InputContext : size_t
	{
		NONE, MENU, TEST1, TEST2,

		IC_COUNT
	} IC;

	typedef enum class InputContextValue : size_t
	{
		NONE,			MENU_SELECT,	MENU_UP,	
		MENU_NEXT,		MENU_PREV,		MENU_DOWN,
		TESTVAL1,TESTVAL2,TESTVAL3,TESTVAL4,

		ICV_COUNT
	} ICV;

	typedef struct InputContextMapping
	{
		InputContextValue	V;
		SDL_Scancode		K;

		InputContextMapping()
		{
			V = ICV::NONE;
			K = SDL_SCANCODE_UNKNOWN;
		}
		InputContextMapping(InputContextValue _v, SDL_Scancode _k)
			: V(_v), K(_k) {}
	} ICM;

	typedef struct InputContextDef
	{
		InputContext	IC_;
		std::vector<InputContextValue> ICVvec_;

		InputContextDef() 
		{
			IC_ = IC::NONE;
			ICVvec_.reserve(10); 
		}
	} ICD;

	typedef struct ICDblank : InputContextDef
	{
		//InputContext	IC_;
		//std::vector<InputContextValue> ICVvec_;

		ICDblank()
		{
			IC_ = IC::NONE;
			ICVvec_.clear();
		}
	} ICD_b;

	// InputController. has functions get_icd() that can
	// be usedi nplace of this (do i want to?)
	//static bool isICVinICD(ICV _icv, ICD _icd)
	//{
	//	for (size_t i=0;i<_icd.ICVvec_.size();++i)
	//	{
	//		if (_icv == _icd.ICVvec_[i]) return true;
	//	}
	//	return false;
	//};
} // END	namespace ss
