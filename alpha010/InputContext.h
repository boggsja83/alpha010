#pragma once

#include "ALL.h"
#include "SDL.h"
#include <vector>

namespace ss
{
	typedef enum class InputContext
	{
		NONE, MENU,
		IC_COUNT
	} IC;

	typedef enum class InputContextValue
	{
		NONE,			MENU_SELECT,	MENU_UP,	
		MENU_NEXT,		MENU_PREV,		MENU_DOWN,
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
		//InputContextDef(IC _ic)
		//{
		//	IC_ = _ic;
		//	ICVvec_.reserve(10);
		//}
	} ICD;

	// move this into object itself (STengMenu)
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
