#pragma once

#include "ALL.h"
#include "SDL.h"
#include <tuple>

namespace ss
{
	typedef enum class InputContextValue //InputContextValue
	{

	}ICV;

	typedef struct InputContext
	{
		std::pair<SDL_Scancode, ICV>	ICS_; // InputContextSymbol
	} IC;
} // END	namespace ss
