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

	//static size_t const		size_IRAO	=	sizeof(bool) * static_cast<size_t>(ICV::ICV_COUNT);
	//typedef std::array<bool, size_IRAO>		Flags_IR;
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

	typedef struct InputReturnType
	{
		IC	IC_ = IC::NONE;
		std::vector<bool>	Flags_;

		enum class p :size_t
		{
			RESERVE = 10
		};

		inline bool operator[](size_t const& _rhs) const
		{
			return Flags_[_rhs];
		}

		inline bool operator==(InputReturnType const& _rhs) const
		{
			if (this->IC_ == _rhs.IC_)
				return true;
			else
				return false;
		}
		inline bool operator<(InputReturnType const& _rhs) const
		{
			if (this->IC_ < _rhs.IC_)
				return true;
			else
				return false;
		}
		
		InputReturnType()
		{
			Flags_.reserve(static_cast<size_t>(p::RESERVE));
			//Input_RX = false;
		}
		InputReturnType(IC& _ic)
		{
			Flags_.reserve(static_cast<size_t>(p::RESERVE));
			IC_ = _ic;
			//Input_RX = false;
		}
		InputReturnType(ICD& _icd)
		{
			Flags_.reserve(_icd.size());
			IC_ = _icd.IC_;
			//Input_RX = false;
		}
		~InputReturnType() {}

		static inline ss::rt set_irt(ICD& _icd, InputReturnType& _irt)
		{
			_irt.IC_ = _icd.IC_;

			_irt.Flags_.clear();
			for (size_t i = 0; i < _icd.size(); ++i)
			{
				_irt.Flags_.push_back(false);
			}
			return rt::OK;
		}

		static inline ss::rt set_irt(ArrICD& _icda, std::array<InputReturnType, static_cast<size_t>(IC::IC_COUNT)>& _irta)
		{
			rt ret = rt::INITIAL;

			for (size_t i = 0; i < _icda.size(); ++i)
			{
				ret = set_irt(_icda[i], _irta[i]);
			}

			return ret;
		}

		inline size_t size() const { return Flags_.size(); }
	} IRT;

	typedef std::array<IRT, static_cast<size_t>(IC::IC_COUNT)> ArrIRT;


	/*--------------------------------------------------*/
	/*---------------------ICDs-------------------------*/
	/*--------------------------------------------------*/
	//typedef struct ICDtest4:InputContextDef
	//{
	//	int const size_ICDL=2;
	//	enum ICDL
	//	{
	//		a=ICV::TESTVAL1,
	//		b=ICV::TESTVAL2,
	//	};

	//}ICD4;

	/*--------------------------------------------------*/

} // END	namespace ss
