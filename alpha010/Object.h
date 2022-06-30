#pragma once

#include "ALL.h"

#include <array>
#include "RectType.h"
#include "SDLwrapper.h"
#include "WinProp.h"

#include "InputContext.h"

namespace ss
{
	class Object
	{
	public:
		Object() :
			ISF_({})
		{ rt ret = init(); }
		~Object() { rt ret = destroy(); }

		/*-----------------INIT/DESTROY--------------------*/
	private:
		inline rt init() 
		{
			IC_ = IC::TEST2;
			//switch back to above! (testing) 6/29/22
			//IC_ = IC::TEST1;

			text_arr[0] = "dtdhnd";
			text_arr[1] = "menu-main";
			text_arr[2] = "test";
			text_arr[3] = "test_2";
			text_arr[4] = "red";

			iTA = 3;

			Dst_.x = 25;
			Dst_.y = 50;
			Dst_.h = 75;
			Dst_.w = 125;

			return rt::OK;
		};
		inline rt destroy() { return rt::OK; };
		/*--------------------------------------------------*/

		/*-------------------VARIABLES----------------------*/
	private:
		char const*		NameCommon_	= "object";
		char const*		NameText_	= "red";

		IC	IC_;
		std::array<bool, 4> ISF_;

		SDL_Rect		Src_;
		SDL_Rect		Dst_;

		

		std::array<char const*, 5> text_arr;
		size_t			iTA;
		/*--------------------------------------------------*/

		/*-------------------FUNCTIONS----------------------*/
	public:
		inline rt input_rx(IRT& _irt)
		{
			//log("input_rx(" << hr(_irt.IC_) << ")");

			for (size_t i = 0; i < _irt.size(); ++i)
			{
				ISF_[i] = _irt[i];
			}

			return rt::OK;
		}

		inline rt update()
		{
			// this really should be push a state (depending on action) ???
			// also need to implement press, range, and toggle input funcitons
			
			/**************************************************/
			if (ISF_[0]) //ICV::TESTVAL1, because Object has ICDtest2...
			/**************************************************/
			{ 
				log("0-W"); 

			}
			/**************************************************/
			if (ISF_[1]) //ICV::TESTVAL2
			/**************************************************/
			{ 
				iTA = (iTA - 1) % 4;//works because c++ % returns int in range of [1,n-1]
			}
			/**************************************************/
			if (ISF_[2]) { log("2-S"); }//ICV::TESTVAL3
			/**************************************************/
			/**************************************************/
			if (ISF_[3]) //ICV::TESTVAL4
			/**************************************************/
			{ 
				iTA = (iTA + 1) % 4;
			}
			/**************************************************/
				//...switch here

				// get this to work
				// need to use ICD.ICVvec....
			//for (size_t i = 0; i < InputStates_.size(); ++i)
			//{
			//	switch (static_cast<ICV>(i))
			//	{
			//	case ICV::TESTVAL1:
			//		log(hr((ICV)i));
			//		break;
			//	case ICV::TESTVAL2:
			//		log(hr((ICV)i));
			//		break;
			//	case ICV::TESTVAL3:
			//		log(hr((ICV)i));
			//		break;
			//	case ICV::TESTVAL4:
			//		log(hr((ICV)i));
			//		break;
			//	default:
			//		;
			//	}
			//}


			return rt::OK;
		}

		inline IC			ic()			{ return IC_; }
		inline char const*	text_name()		{ return text_arr[iTA]; }
		inline char const*	common_name()	{ return NameCommon_; }
		inline SDL_Rect*	get_rect()		{ return &Dst_; }
		/*--------------------------------------------------*/

	}; // END	class Object
} // END	namespace ss
