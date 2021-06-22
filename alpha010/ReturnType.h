#pragma once

namespace ss
{

	static int8_t constexpr rerr8 = static_cast<int8_t>(0xFF);

	// (this was just for enum not enum class...) C-style way, C++ doesnt really care (e_ret_t or blank there)
	typedef enum class ec_ret_t:int8_t
	{
		SUCCESS,					INITIAL,
		
		STATE_STACK_EMPTY,			ALREADY_IN_LIST,		OUT_OF_BOUNDS,
		
		NOT_IN_LIST,				FAIL_GENERIC,

		FAIL_SET_REND_DRAW_COLOR,	FAIL_SET_REND_TARG,

		FAIL_GET_REND_INFO,

		FAIL_INIT_SDL,				FAIL_INIT_SDL_VIDEO,	FAIL_INIT_IMG,
		
		FAIL_CREATE_WIN,			FAIL_CREATE_REND,		FAIL_CREATE_TEXT,
		FAIL_CREATE_SURF,

		FAIL_DESTROY_WIN,			FAIL_DESTROY_REND,		FAIL_DESTROY_TEXT, 
		FAIL_DESTROY_SURF,			FAIL_DESTROY_SDL,		FAIL_DESTROY_SDL_VIDEO,
		FAIL_DESTROY_SDL_IMG,

		FAIL_QUERY_TEXT,
		FAIL_FILL_RECT,
		FAIL_UPDATE_WIN_SURF,
		FAIL_REND_CPY,


		COUNT_RET_T	//if this is last, will always be number of member elements in enum
					//not including this as an entry
					//...unless i make levels like FAIL_INIT_SDL=200; starts 200 level...
	} rt;

	static char const *const rt_ret_m[] =
	{
		"SUCCESS",					"INITIAL",

		"STATE_STACK_EMPTY",		"ALREADY_IN_LIST",		"OUT_OF_BOUNDS",

		"NOT_IN_LIST",				"FAIL_GENERIC",

		"FAIL_SET_REND_DRAW_COLOR",	"FAIL_SET_REND_TARG",

		"FAIL_GET_REND_INFO",

		"FAIL_INIT_SDL",			"FAIL_INIT_SDL_VIDEO",	"FAIL_INIT_IMG",

		"FAIL_CREATE_WIN",			"FAIL_CREATE_REND",		"FAIL_CREATE_TEXT",
		"FAIL_CREATE_SURF",

		"FAIL_DESTROY_WIN",			"FAIL_DESTROY_REND",	"FAIL_DESTROY_TEXT",
		"FAIL_DESTROY_SURF",		"FAIL_DESTROY_SDL",		"FAIL_DESTROY_SDL_VIDEO",
		"FAIL_DESTROY_SDL_IMG",

		"FAIL_QUERY_TEXT",
		"FAIL_FILL_RECT",
		"FAIL_UPDATE_WIN_SURF",
		"FAIL_REND_CPY",


		"COUNT_RET_T"
	};

	static constexpr char const* c2m(rt _code)
	{
		size_t temp_s = static_cast<size_t>(_code);
		if ((temp_s >= 0) && (temp_s < static_cast<size_t>(rt::COUNT_RET_T)))
			return rt_ret_m[temp_s];
		else return "RET_CODE_OUT_OF_BOUNDS";
	}

	static constexpr char const* c2m(size_t _code)
	{
		if ((_code >= 0) && (_code < static_cast<size_t>(rt::COUNT_RET_T)))
			return rt_ret_m[_code];
		else return "RET_CODE_OUT_OF_BOUNDS";
	}

	static constexpr char const * c2m(int8_t _code)
	{
		if ( (_code >= 0) && (_code < static_cast<int8_t>(rt::COUNT_RET_T)) )
			return rt_ret_m[_code];
		else return "RET_CODE_OUT_OF_BOUNDS";
	}

	static constexpr char const* c2m(int _code)
	{
		if ((_code >= 0) && (_code < static_cast<int>(rt::COUNT_RET_T)))
			return rt_ret_m[_code];
		else return "RET_CODE_OUT_OF_BOUNDS";
	}

} // END	namespace ss
