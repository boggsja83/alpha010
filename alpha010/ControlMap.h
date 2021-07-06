#pragma once

#include "ALL.h"
#include "InputContext.h"
#include <array>

namespace ss
{
	typedef struct ControlMap
	{
		std::array<InputContextMapping,static_cast<size_t>(ICV::ICV_COUNT)> Map_;

		inline ICM& operator[](std::size_t _rhs) { return Map_[static_cast<size_t>(_rhs)]; }
		inline ICM& operator[](ICV _rhs) { return Map_[static_cast<size_t>(_rhs)]; }
		
		//int f = ICD4::size_ICDL;
		//ICV i = static_cast<ICV>(ICD4::ICDL::a);

		ControlMap()
		{
			// indeces coincide with InputContextValue enum's
			size_t i = 0;
			
			Map_[i].V	= ICV::NONE;
			Map_[i++].K	= SDL_SCANCODE_UNKNOWN;

			Map_[i].V	= ICV::MENU_SELECT;
			Map_[i++].K	= SDL_SCANCODE_RETURN;

			Map_[i].V	= ICV::MENU_UP;
			Map_[i++].K	= SDL_SCANCODE_UP;

			Map_[i].V	= ICV::MENU_NEXT;
			Map_[i++].K	= SDL_SCANCODE_RIGHT;

			Map_[i].V	= ICV::MENU_PREV;
			Map_[i++].K	= SDL_SCANCODE_LEFT;

			Map_[i].V	= ICV::MENU_DOWN;
			Map_[i++].K	= SDL_SCANCODE_DOWN;

			Map_[i].V	= ICV::TESTVAL1;
			Map_[i++].K	= SDL_SCANCODE_W;

			Map_[i].V	= ICV::TESTVAL2;
			Map_[i++].K	= SDL_SCANCODE_A;

			Map_[i].V	= ICV::TESTVAL3;
			Map_[i++].K	= SDL_SCANCODE_S;

			Map_[i].V	= ICV::TESTVAL4;
			Map_[i++].K	= SDL_SCANCODE_D;

			Map_[i].V = ICV::TESTVAL5;
			Map_[i++].K = SDL_SCANCODE_1;

			Map_[i].V = ICV::TESTVAL6;
			Map_[i++].K = SDL_SCANCODE_2;
		
		}
		
	} CM;

} // END	namespace ss
