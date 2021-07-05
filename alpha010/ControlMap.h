#pragma once

#include "ALL.h"
#include "InputContext.h"
#include <array>

namespace ss
{
	typedef struct ControlMap
	{
		std::array<InputContextMapping,static_cast<size_t>(ICV::ICV_COUNT)> Map;

		ControlMap()
		{
			size_t i = 0;
			
			Map[i].V	= ICV::NONE;
			Map[i++].K	= SDL_SCANCODE_UNKNOWN;

			Map[i].V	= ICV::MENU_SELECT;
			Map[i++].K	= SDL_SCANCODE_RETURN;

			Map[i].V	= ICV::MENU_UP;
			Map[i++].K	= SDL_SCANCODE_UP;

			Map[i].V	= ICV::MENU_NEXT;
			Map[i++].K	= SDL_SCANCODE_RIGHT;

			Map[i].V	= ICV::MENU_PREV;
			Map[i++].K	= SDL_SCANCODE_LEFT;

			Map[i].V	= ICV::MENU_DOWN;
			Map[i++].K	= SDL_SCANCODE_DOWN;

			Map[i].V	= ICV::TESTVAL1;
			Map[i++].K	= SDL_SCANCODE_W;

			Map[i].V	= ICV::TESTVAL2;
			Map[i++].K	= SDL_SCANCODE_A;

			Map[i].V	= ICV::TESTVAL3;
			Map[i++].K	= SDL_SCANCODE_S;

			Map[i].V	= ICV::TESTVAL4;
			Map[i++].K	= SDL_SCANCODE_D;

			Map[i].V = ICV::TESTVAL5;
			Map[i++].K = SDL_SCANCODE_1;

			Map[i].V = ICV::TESTVAL6;
			Map[i++].K = SDL_SCANCODE_2;
		
		}
		
	} CM;

} // END	namespace ss
