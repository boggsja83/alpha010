#pragma once

#include "ALL.h"
#include "SDL.h"
#include <vector>


// 7/5 3:00pm 
// -going to work on ooperator overloads...
// working on moving all ICDs to this file,
// put a ICMgr struct/class in here to hold
// instances of ICDs?


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
		InputContextDef()
		{
			IC_ = IC::NONE;
			ICVvec_.reserve(10);
		}

		InputContext	IC_;
		std::vector<InputContextValue> ICVvec_;

		inline size_t size() const { return ICVvec_.size(); }


		inline InputContextValue& operator[](std::size_t _rhs) 
		{ 
			return ICVvec_[_rhs]; 
		}

		inline bool operator==(InputContext const& _rhs) const
		{
			if (this->IC_ == _rhs)
				return true;
			else
				return false;
		}
		inline bool operator<(InputContext const& _rhs) const
		{
			if (this->IC_ < _rhs)
				return true;
			else
				return false;
		}
		inline bool operator==(InputContextDef const& _rhs) const
		{
			if (this->IC_ == _rhs.IC_)
				return true;
			else
				return false;
		}
		inline bool operator<(InputContextDef const& _rhs) const
		{
			if (this->IC_ < _rhs.IC_)
				return true;
			else
				return false;
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
	} ICD_B;

	static size_t constexpr	size_SC		=	sizeof(bool) * 300;
	static size_t const		size_IRAO	=	sizeof(bool) * static_cast<size_t>(ICV::ICV_COUNT);
	typedef std::array<bool, size_SC>		Flags_SC;
	typedef std::array<bool, size_IRAO>		Flags_IR;
	typedef std::array<InputContext, static_cast<size_t>
							(IC::IC_COUNT)>	ArrIC;
	typedef std::array<InputContextDef, static_cast<size_t>
							(IC::IC_COUNT)>	ArrICD;

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




	/*--------------------------------------------------*/
	/*---------------------ICDs-------------------------*/
	/*--------------------------------------------------*/
	typedef struct ICDtest4:InputContextDef
	{
		int const size_ICDL=2;
		enum ICDL
		{
			a=ICV::TESTVAL1,
			b=ICV::TESTVAL2,
		};

	}ICD4;

	/*--------------------------------------------------*/

} // END	namespace ss
