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
			
			
			//CM_[i++] = ICM(ICV::MENU_SELECT, SDL_SCANCODE_RETURN);
			//CM_[i++] = ICM(ICV::MENU_UP, SDL_SCANCODE_UP);
			//CM_[i++] = ICM(ICV::MENU_NEXT, SDL_SCANCODE_RIGHT);
			//CM_[i++] = ICM(ICV::MENU_PREV, SDL_SCANCODE_LEFT);
			//CM_[i++] = ICM(ICV::MENU_DOWN, SDL_SCANCODE_DOWN);
		}
		
	} CM;

} // END	namespace ss
