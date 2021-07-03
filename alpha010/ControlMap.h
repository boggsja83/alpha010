#pragma once

#include "ALL.h"
#include "InputContext.h"
#include <array>

namespace ss
{
	typedef struct ControlMap
	{
		std::array<InputContextMapping,static_cast<size_t>(ICV::ICV_COUNT)> CM_;

		ControlMap()
		{
			size_t i = 0;
			
			CM_[i].V	= ICV::NONE;
			CM_[i++].K	= SDL_SCANCODE_UNKNOWN;

			CM_[i].V	= ICV::MENU_SELECT;
			CM_[i++].K	= SDL_SCANCODE_RETURN;

			CM_[i].V	= ICV::MENU_UP;
			CM_[i++].K	= SDL_SCANCODE_UP;

			CM_[i].V	= ICV::MENU_NEXT;
			CM_[i++].K	= SDL_SCANCODE_RIGHT;

			CM_[i].V	= ICV::MENU_PREV;
			CM_[i++].K	= SDL_SCANCODE_LEFT;

			CM_[i].V	= ICV::MENU_DOWN;
			CM_[i++].K	= SDL_SCANCODE_DOWN;

			CM_[i].V	= ICV::TESTVAL1;
			CM_[i++].K	= SDL_SCANCODE_W;

			CM_[i].V	= ICV::TESTVAL2;
			CM_[i++].K	= SDL_SCANCODE_A;

			CM_[i].V	= ICV::TESTVAL3;
			CM_[i++].K	= SDL_SCANCODE_S;

			CM_[i].V	= ICV::TESTVAL4;
			CM_[i++].K	= SDL_SCANCODE_D;
		
		}
		
	} CM;

} // END	namespace ss
