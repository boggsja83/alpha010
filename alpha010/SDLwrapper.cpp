//#include "SDLwrapper.h"
//
//int ss::init_sdl_video()
//{
//	SDL_ClearError();
//	int r = SDL_InitSubSystem(SDL_INIT_VIDEO);
//	
//	if (r)
//	{ log("init_sdl_video error: " << SDL_GetError()); return r; }
//	else
//	{ log("init_sdl_video()"); }
//	return r;
//}
//
//uint8_t ss::init_sdl_img()
//{
//	//Initialize PNG loading
//	Uint32 flags = IMG_INIT_PNG;
//	IMG_GetError();
//	int r = IMG_Init(flags);
//	if ((r & flags) != flags)
//	{
//		log("SDL image could not initialize:" << IMG_GetError());
//		return 0xF;
//	}
//	else
//	{
//		log("init_sdl_img()");
//		return 0x0;
//	}
//}
//
//SDL_Window* ss::create_win(char const* _title, int _x, int _y, int _w, int _h, Uint32 _flags)
//{
//	SDL_Window* temp = nullptr;
//
//	SDL_ClearError();
//	temp = SDL_CreateWindow(
//		_title,
//		_x, _y,
//		_w, _h,
//		_flags
//	);
//
//	if (temp)
//	{ log("create_win(): " << temp); }
//	else
//	{ log("create_win() error: " << SDL_GetError()); }
//	return temp;
//}
//
//SDL_Renderer* ss::create_rend(SDL_Window* _win, int _index, Uint32 _flags)
//{
//	SDL_Renderer* temp = nullptr;
//	SDL_ClearError();
//	temp = SDL_CreateRenderer(_win, _index, _flags);
//
//	if (temp)
//	{ log("create_rend(): " << temp); }
//	else{ log("create_rend() error: " << SDL_GetError()); }
//	return temp;
//}
//
//SDL_Surface* ss::create_surf_from_path(char const* _path)
//{
//	SDL_Surface* temp = nullptr;
//	IMG_GetError();
//	temp = IMG_Load(_path);
//	if (temp)
//	{
//		//good
//		log("create_surf_from_path()");
//	}
//	else
//	{
//		//bad
//		log("create_surf_from_path() error: " << IMG_GetError());
//	}
//	return temp;
//}
//
//SDL_Texture* ss::create_text(SDL_Renderer* _rend, Uint32 _format, int _access, int _w, int _h)
//{
//	// format can be whole lot of things...
//	// 
//	// access
//	// SDL_TEXTUREACCESS_STATIC changes rarely, not lockable
//	// SDL_TEXTUREACCESS_STREAMING changes frequently, lockable
//	// SDL_TEXTUREACCESS_TARGET can be used as a render target
//
//	// w width
//	// h height
//
//	SDL_Texture* text = nullptr;
//
//	SDL_ClearError();
//	text = SDL_CreateTexture(_rend, _format, _access, _w, _h);
//	if (text) { log("create_text(): " << text); }
//	else { log("create_text() error: " << SDL_GetError()); }
//	return text;
//}
//
//SDL_Texture* ss::create_text_from_surf(SDL_Renderer* _rend, SDL_Surface* _surf)
//{
//	SDL_ClearError();
//	SDL_Texture* t = SDL_CreateTextureFromSurface(_rend, _surf);
//	if (!t) { log("create_text_from_surf(" << _rend << ", " << _surf << ") error: " << SDL_GetError()); }
//	return t;
//}
//
//SDL_Texture* ss::create_text_from_path(SDL_Renderer* _rend, char const* _path)
//{
//	SDL_Surface* temp_s = nullptr;
//	SDL_Texture* temp_t = nullptr;
//
//	temp_s = create_surf_from_path(_path);
//	if (temp_s)
//	{
//		temp_t = create_text_from_surf(_rend, temp_s);
//		uint8_t r = destroy_surf(temp_s);
//
//		if (!temp_t) { log("create_text_from_path() failed to create texture: " << _path); }
//	}
//	else { log("create_surf_from_path() failed to create surface: " << _path); }
//
//	return temp_t;
//}
//
//int ss::set_rend_draw_color(SDL_Renderer* _rend, uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a)
//{
//	SDL_ClearError();
//	int ret = SDL_SetRenderDrawColor(_rend, _r, _g, _b, _a);
//	if(ret) { log("set_rend_draw_color failed: " << SDL_GetError()); }
//	return ret;
//}
//
//int ss::set_rend_targ(SDL_Renderer* _r, SDL_Texture* _t)
//{
//	SDL_ClearError();
//	int r = SDL_SetRenderTarget(_r, _t);
//	if (r) { log("set_rend_targ(" << _r << ", " << _t << ") error: " << SDL_GetError()); }
//	return r;
//}
//
//int32_t ss::get_pixel_format(SDL_RendererInfo* _ri)
//{
//	//int n = _ri->num_texture_formats;
//	//Uint32 u = 0;
//
//	//for (int i=0; i<n;++i)
//	//{
//	//	u = _ri->texture_formats[i];
//	//}
//	//
//	//return u;
//	return _ri->texture_formats[0];
//}
//
//int ss::get_rend_info(SDL_Renderer* _r, SDL_RendererInfo* _ri)
//{
//	SDL_ClearError();
//	int r = SDL_GetRendererInfo(_r, _ri);
//	if (r) { log("get_rend_info("<<_r<<", "<<_ri<<") error: " << SDL_GetError()); }
//	return r;
//}
//
//int ss::fill_rect(SDL_Surface* _src, SDL_Rect* _rect, Uint32 _color)
//{
//	SDL_ClearError();
//	int ret = SDL_FillRect(_src, _rect, _color);
//	if (ret) { log("ss::fill_rect("<<_src<<", "<<_rect<<", "<<_color<<") error: " << SDL_GetError()); }
//	return ret;
//}
//
//int ss::query_text(SDL_Texture* _text, Uint32* _format, int* _access, int* _w, int* _h)
//{
//	//int SDL_QueryTexture(SDL_Texture * texture,
//	//	Uint32 * format, int* access,
//	//	int* w, int* h);
//
//	int r = -1;
//
//	SDL_ClearError();
//	r = SDL_QueryTexture(_text, _format, _access, _w, _h);
//	if (r)
//	{
//		//bad
//		log("query_text(" <<
//			_text << ", " <<
//			_format << ", " <<
//			_access << ", " <<
//			_w << ", " << _h <<
//			") error: " << SDL_GetError());
//	}
//	return r;
//}
//
//SDL_Surface* ss::get_win_surf(SDL_Window* _win)
//{
//	SDL_ClearError();
//	SDL_Surface* ret = SDL_GetWindowSurface(_win);
//	if (!ret) { log("ss::get_win_surf("<<_win<<") error: " << SDL_GetError()); }
//	return ret;
//}
//
//int ss::update_win_surf(SDL_Window* _win)
//{
//	SDL_ClearError();
//	int ret = SDL_UpdateWindowSurface(_win);
//	if (ret) { log("ss:update_win_surf("<<_win<<") error: " << SDL_GetError()); }
//	return ret;
//}
//
//int ss::rend_cpy(SDL_Renderer* _rend, SDL_Texture* _text, SDL_Rect const* _src, SDL_Rect const* _dst)
//{
//	SDL_ClearError();
//	int ret = SDL_RenderCopy(_rend, _text, _src, _dst);
//	if (ret) { log("rend_cpy(" << _rend << ", " << _text << ", " << _src << ", " << _dst << ") error: " << SDL_GetError()); }
//	return ret;
//}
//
//uint8_t ss::destroy_win(SDL_Window* _w)
//{
//	SDL_ClearError();
//	SDL_DestroyWindow(_w);
//	std::string s = SDL_GetError();
//	if (s.size()==0)
//	{
//		// good
//		log("destroy_win(" << _w << ")");
//		return 0x00;
//	}
//	else
//	{
//		// bad
//		log("destroy_win error: " << s);
//		return 0xFF;
//	}
//}
//
//uint8_t ss::destroy_rend(SDL_Renderer* _r)
//{
//	SDL_ClearError();
//	SDL_DestroyRenderer(_r);
//	std::string s = SDL_GetError();
//	if (s.size() == 0)
//	{
//		// good
//		log("destroy_rend(" << _r << ")");
//		return 0x0;
//	}
//	else
//	{
//		// bad
//		log("destroy_rend(" << _r << ") error: " << s);
//		return 0xFF;
//	}
//}
//
//uint8_t ss::destroy_text(SDL_Texture* _t)
//{
//	SDL_ClearError();
//	SDL_DestroyTexture(_t);
//	std::string s = SDL_GetError();
//	if (s.size() == 0)
//	{
//		// good
//		log("destroy_text(" << std::hex << (int32_t)_t << ")");
//		return 0x0;
//	}
//	else
//	{
//		// bad
//		log("destroy_text(" << _t << ") error: " << s);
//		return 0xF;
//	}
//}
//
//uint8_t ss::destroy_surf(SDL_Surface* _s)
//{
//	// safe to pass null to
//
//	SDL_ClearError();
//	SDL_FreeSurface(_s);
//	std::string s = SDL_GetError();
//	if (s.size() == 0)
//	{
//		log("destroy_surf(" << _s << ")");
//		return 0x0;
//	}
//	else
//	{
//		log("destroy_surf(" << _s << ") error: " << s);
//		return 0xF;
//	}
//}
//
//uint8_t ss::destroy_sdl()
//{
//	SDL_ClearError();
//	SDL_Quit();
//	std::string s = SDL_GetError();
//	if (s.size() == 0)
//	{
//		//good
//		log("destroy_sdl() " << s);
//		return 0x0;
//	}
//	else
//	{
//		//bad
//		log("destroy_sdl() error: " << s);
//		return 0xF;
//	}
//}
//
//uint8_t ss::destroy_sdl_video()
//{
//	SDL_ClearError();
//	SDL_QuitSubSystem(SDL_INIT_VIDEO);
//	std::string s = SDL_GetError();
//	if (s.size() == 0)
//	{
//		//good
//		log("destroy_sdl_video() " << s);
//		return 0x0;
//	}
//	else
//	{
//		//bad
//		log("destroy_sdl_error() error: " << s);
//		return 0xF;
//	}
//}
//
//uint8_t ss::destroy_sdl_image()
//{
//	std::string s = IMG_GetError();
//	IMG_Quit();
//	s = IMG_GetError();
//	if (s.size() == 0)
//	{
//		//good
//		log("destroy_sdl_image() " << s);
//		return 0x0;
//	}
//	else
//	{
//		//bad
//		log("destroy_sdl_image() error: " << s);
//		return 0xF;
//	}
//}
//
