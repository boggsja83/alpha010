#pragma once

#include "SDL.h"

namespace ss
{
	static	int8_t				const	index_rend			= (int8_t)0xFF; // = -1, first available system hardware renderer
	static	int32_t				const	flags_rend			= 0x00;
	static	SDL_RendererInfo			info_rend			;
	static	uint32_t					pixel_format_rend	= 0x00;
	static  uint8_t				const	text_access_target			= SDL_TEXTUREACCESS_TARGET;
	static	int8_t				const	r_rend				= (int8_t)0x00;
	static	int8_t				const	g_rend				= (int8_t)0xFF;
	static	int8_t				const	b_rend				= (int8_t)0x00;
	static	int8_t				const	a_rend				= (int8_t)SDL_ALPHA_OPAQUE;
}	// END	namespace ss
