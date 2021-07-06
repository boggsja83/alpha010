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
		Object() { rt ret = init(); }
		~Object() { rt ret = destroy(); }

		/*-----------------INIT/DESTROY--------------------*/
	private:
		inline rt init() 
		{
			IC_ = IC::TEST2;

			text_arr[0] = "dtdhnd";
			text_arr[1] = "menu-main";
			text_arr[2] = "test";
			text_arr[3] = "test_2";
			text_arr[4] = "red";

			iTA = 4;

			Rect_.x = 25;
			Rect_.y = 50;
			Rect_.h = 75;
			Rect_.w = 125;

			return rt::OK;
		};
		inline rt destroy() { return rt::OK; };
		/*--------------------------------------------------*/

		/*-------------------VARIABLES----------------------*/
	private:
		char const*		Name_com_	= "object";
		char const*		Name_text_	= "menu-main";
		IC	IC_;
		
		SDL_Rect		Rect_;

		

		std::array<char const*, 5> text_arr;
		size_t			iTA;
		/*--------------------------------------------------*/

		/*-------------------FUNCTIONS----------------------*/
	public:
		inline rt input_rx(Flags_IR& _ir)
		{
			//log("input_rx(" << _irao.size() << ")");

			for (size_t i=0; i<size_IRAO; ++i)
			{
				if (_ir[i])
				{
					switch(static_cast<ICV>(i))
					{
					case ICV::TESTVAL1:
						log("1");
						break;
					case ICV::TESTVAL2:
						log("2");
						break;
					case ICV::TESTVAL3:
						log("3");
						break;
					case ICV::TESTVAL4:
						log("4");
						break;
					default:
						log("default");
						;
					}
				}
			}

			return rt::OK;
		}

		inline IC			ic()			{ return IC_; }
		inline char const*	text_name()		{ return text_arr[iTA]; }
		inline char const*	common_name()	{ return Name_com_; }
		inline SDL_Rect*	get_rect()		{ return &Rect_; }
		/*--------------------------------------------------*/

	}; // END	class Object
} // END	namespace ss
