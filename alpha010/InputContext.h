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
	// move this into object itself (STengMenu)??
	//typedef struct ICDengMenu : InputContextDef
	//{
	//	//InputContext	IC_;
	//	//std::vector<InputContextValue> ICVvec_;

	//	ICDengMenu()
	//	{
	//		IC_ = IC::MENU;

	//		ICVvec_.push_back(ICV::MENU_SELECT);
	//		ICVvec_.push_back(ICV::MENU_UP);
	//		ICVvec_.push_back(ICV::MENU_DOWN);
	//		ICVvec_.push_back(ICV::MENU_NEXT);
	//		ICVvec_.push_back(ICV::MENU_PREV);
	//	}
	//} ICD_mm;
} // END	namespace ss
