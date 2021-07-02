#pragma once

#include "SDL.h"

namespace ss
{
	static	constexpr char	const	*title_win	=	"the-base";
	static	size_t	constexpr	width_win	=	300;
	static	size_t	constexpr	height_win	=	500;
	static	size_t	constexpr	x_win		=	1920-256-50;
	static	size_t	constexpr	y_win		=	1080-540;
	static	int32_t	constexpr	flags_win	=	(int32_t)(SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);// | SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);;

	static	int8_t	constexpr	r_surf		=	(int8_t)0xFF;
	static	int8_t	constexpr	g_surf		=	(int8_t)0x00;
	static	int8_t	constexpr	b_surf		=	(int8_t)0x00;
	static	SDL_Rect	const	rect_win		{0,0,width_win,height_win};
} // END	namespace ss
