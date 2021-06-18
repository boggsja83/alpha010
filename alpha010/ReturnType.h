#pragma once

namespace ss
{
	// (this was just for enum not enum class...) C-style way, C++ doesnt really care (e_ret_t or blank there)
	typedef enum class e_ss_ret_t
	{
		SUCCESS,					INITIAL,
		
		STATE_STACK_EMPTY,
		
		FAIL_SET_REND_DRAW_COLOR,	FAIL_SET_REND_TARG,

		FAIL_GET_RENDER_INFO,

		FAIL_INIT_SDL,				FAIL_INIT_SDL_VIDEO,	FAIL_INIT_IMG,
		
		FAIL_CREATE_WIN,			FAIL_CREATE_REND,		FAIL_CREATE_TEXT,

		FAIL_DESTROY_WIN,			FAIL_DESTROY_REND,		FAIL_DESTROY_TEXT, 
		FAIL_DESTROY_SURF,			FAIL_DESTROY_SDL,		FAIL_DESTROY_SDL_VIDEO,
		FAIL_DESTROY_SDL_IMG,

		FAIL_FILL_RECT,
		FAIL_UPDATE_WIN_SURF,
		FAIL_REND_CPY,


		RET_T_COUNT	//if this is last, will always be number of member elements in enum
					//not including this as an entry
					//...unless i make levels like FAIL_INIT_SDL=200; starts 200 level...
	} rt;

	static char const *const e_ss_ret_m[] =
	{
		"SUCCESS",					"INITIAL",

		"STATE_STACK_EMPTY",

		"FAIL_SET_REND_DRAW_COLOR",	"FAIL_SET_REND_TARG",

		"FAIL_GET_RENDER_INFO",

		"FAIL_INIT_SDL",			"FAIL_INIT_SDL_VIDEO",	"FAIL_INIT_IMG",

		"FAIL_CREATE_WIN",			"FAIL_CREATE_REND",		"FAIL_CREATE_TEXT",

		"FAIL_DESTROY_WIN",			"FAIL_DESTROY_REND",	"FAIL_DESTROY_TEXT",
		"FAIL_DESTROY_SURF",		"FAIL_DESTROY_SDL",		"FAIL_DESTROY_SDL_VIDEO",
		"FAIL_DESTROY_SDL_IMG",

		"FAIL_FILL_RECT",
		"FAIL_UPDATE_WIN_SURF",
		"FAIL_REND_CPY",


		"RET_T_COUNT/not really used(bufferoverflow-ish)"
	};


} // END	namespace ss
