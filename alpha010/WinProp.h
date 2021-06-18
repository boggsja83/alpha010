#pragma once

#include "SDL.h"

namespace ss
{
	static	char		const	*title_win	=	"the-base";
	static	size_t		const	width_win	=	256;
	static	size_t		const	height_win	=	256;
	static	size_t		const	x_win		=	1920-256-50;
	static	size_t		const	y_win		=	100;
	static	int32_t		const	flags_win	=	(int32_t)(SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);// | SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);;

	static	int8_t		const	r_surf		=	(int8_t)0xFF;
	static	int8_t		const	g_surf		=	(int8_t)0x00;
	static	int8_t		const	b_surf		=	(int8_t)0x00;
	static	SDL_Rect	const	rect_win		{0,0,width_win,height_win};
} // END	namespace ss
