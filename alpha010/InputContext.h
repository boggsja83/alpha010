#pragma once

#include "ALL.h"
#include "SDL.h"
#include <tuple>

namespace ss
{
	typedef enum class InputContext
	{
		MENU
	} IC;

	typedef enum class InputContextValue
	{
		MENU_SELECT,	MENU_UP,	MENU_DOWN,
		MENU_NEXT,		MENU_PREV
	} ICV;

	typedef struct InputContextMapping
	{
		InputContextValue	V;
		SDL_Scancode		K;

		InputContextMapping(InputContextValue _v, SDL_Scancode _k)
			: V(_v), K(_k) {}
		//InputContextMapping() = delete;
	} ICMI;

} // END	namespace ss
