#pragma once

#include "SDL.h"

namespace ss
{
	static	constexpr char		const	*title_win	=	"the-base";
	static	constexpr size_t	const	width_win	=	256;
	static	constexpr size_t	const	height_win	=	256;
	static	constexpr size_t	const	x_win		=	1920-256-50;
	static	constexpr size_t	const	y_win		=	1080-540;
	static	constexpr int32_t	const	flags_win	=	(int32_t)(SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);// | SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);;

	static	constexpr int8_t	const	r_surf		=	(int8_t)0xFF;
	static	constexpr int8_t	const	g_surf		=	(int8_t)0x00;
	static	constexpr int8_t	const	b_surf		=	(int8_t)0x00;
	static	constexpr SDL_Rect	const	rect_win		{0,0,width_win,height_win};
} // END	namespace ss
