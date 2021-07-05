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
		TESTVAL1,TESTVAL2,TESTVAL3,
		TESTVAL4, TESTVAL5, TESTVAL6,

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

		bool operator==(InputContextDef const& _rhs)
		{
			if (this->IC_ == _rhs.IC_)
				return true;
			else
				return false;
		}
		bool operator<(InputContextDef const& _rhs)
		{
			if (this->IC_ < _rhs.IC_)
				return true;
			else
				return false;
		}

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


	static char const* hr(IC _ic)
	{
		if (_ic<IC::NONE || _ic>IC::IC_COUNT) return nullptr;
		
		char const* arr[] = { 
			"NONE", "MENU",
			"TEST1", "TEST2",
			"IC_COUNT"	
		};

		return arr[static_cast<size_t>(_ic)];
	}

	static char const* hr(ICV _icv)
	{
		if (_icv<ICV::NONE || _icv>ICV::ICV_COUNT) return nullptr;

		char const* arr[] = {
		"NONE",			"MENU_SELECT",	"MENU_UP",
		"MENU_NEXT",		"MENU_PREV",		"MENU_DOWN",
		"TESTVAL1","TESTVAL2","TESTVAL3",
		"TESTVAL4", "TESTVAL5", "TESTVAL6",

		"ICV_COUNT"
		};

		return arr[static_cast<size_t>(_icv)];
	}

} // END	namespace ss
