#include "SDL_.h"

//using namespace ss;

uint8_t ss::sdl_::init()
{
	uint8_t r = -1;

	r = init_locals();
	if (r) return r;

	r = init_sdl_video();
	if (r) return r;

	r = init_sdl_img();
	if (r) return r;

	Win_ = create_win(title_win, x_win, y_win, width_win, height_win, flags_win);
	if (!Win_) return -4;

	Rend_ = create_rend(Win_, index_rend, flags_rend);
	if (!Rend_) return -5;

	// red window surface
	Surface_ = SDL_GetWindowSurface(Win_);
	SDL_FillRect(Surface_, &rect_win,
		SDL_MapRGB(Surface_->format, r_surf, g_surf, b_surf) );
	SDL_UpdateWindowSurface(Win_);

	// green renderer
	SDL_SetRenderDrawColor(Rend_, r_rend, g_rend, b_rend, SDL_ALPHA_OPAQUE);

	//SDL_RendererInfo _ri;
	r = get_rend_info(Rend_, &info_rend);
	pixel_format_rend = get_pixel_format(&info_rend);
	Texture_ = create_text(Rend_, pixel_format_rend, SDL_TEXTUREACCESS_TARGET, rect_win.w, rect_win.h);

	return 0x0;
}

uint8_t ss::sdl_::init_locals()
{
	//buffer_index = false;
	//buffer[0] = nullptr;
	//buffer[1] = nullptr;

	Win_ = nullptr;
	Rend_ = nullptr;
	Surface_ = nullptr;
	Texture_ = nullptr;

	title_win = "tic-tac-toe";
	width_win = 800;
	height_win = 600;
	x_win = 200;
	y_win = 200;
	flags_win = (int32_t)(SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);// | SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);

	r_surf = (int8_t)0xFF;
	g_surf = (int8_t)0x00;
	b_surf = (int8_t)0x00;

	//rect_ = nullptr;
	rect_win.x = 0;// x_win;
	rect_win.y = 0;// y_win;
	rect_win.h = height_win;
	rect_win.w = width_win;

	index_rend = (int8_t)0xFF;// -1;//first system video device
	flags_rend = 0x00;// could cast from SDL_RENDER_FLAGS

	r_rend = (int8_t)0x00;
	g_rend = (int8_t)0xFF;
	b_rend = (int8_t)0x00;

	//SDL_RendererInfo _ri;
	//int r = get_rend_info(Rend_, &_ri);
	pixel_format_rend = 0;// get_pixel_format(&_ri);

	return 0x0;
}

int ss::sdl_::init_sdl_video() const
{
	SDL_ClearError();
	int r = SDL_InitSubSystem(SDL_INIT_VIDEO);
	
	if (r)
	{
		//bad
		log("init_sdl_video error: " << SDL_GetError());
		return r;
	}
	else
	{
		//good
		log("init_sdl_video()");// " << SDL_GetError());
		return r;
	}
}

uint8_t ss::sdl_::init_sdl_img() const
{
	//Initialize PNG loading
	Uint32 flags = IMG_INIT_PNG;
	IMG_GetError();
	int r = IMG_Init(flags);
	if ((r & flags) != flags)
	{
		log("SDL image could not initialize:" << IMG_GetError());
		return 0xF;
	}
	else
	{
		log("init_sdl_img()");
		return 0x0;
	}
}

SDL_Window* ss::sdl_::create_win(char const* _title, int _x, int _y, int _w, int _h, Uint32 _flags) const
{
	SDL_Window* temp = nullptr;

	SDL_ClearError();
	temp = SDL_CreateWindow(
		_title,
		_x, _y,
		_w, _h,
		_flags
	);
	if (temp)
	{
		// good
		log("create_win(): " << temp);
		//surface_ = SDL_GetWindowSurface(win_);
		//SDL_FillRect(
		//	surface_,
		//	&rect_,
		//	SDL_MapRGB(surface_->format, r_, g_, b_)
		//);
		//SDL_UpdateWindowSurface(win_);
		//return temp;
	}
	else
	{
		// bad
		log("create_win() error: " << SDL_GetError());
		//return nullptr;
	}
	return temp;
}

SDL_Renderer* ss::sdl_::create_rend(SDL_Window* _win, int _index, Uint32 _flags) const
{
	SDL_Renderer* temp = nullptr;
	SDL_ClearError();
	temp = SDL_CreateRenderer(_win, _index, _flags);

	if (temp)
	{
		//good
		log("create_rend(): " << temp);
		//return temp;
	}
	else
	{
		//bad
		log("create_rend() error: " << SDL_GetError());
		//return nullptr;
	}
	return temp;
}

SDL_Surface* ss::sdl_::create_surf_from_path(char const* _path) const
{
	//SDL_Surface *IMG_Load(const char *file)

	SDL_Surface* temp = nullptr;
	IMG_GetError();
	temp = IMG_Load(_path);
	if (temp)
	{
		//good
		log("create_surf_from_path()");
	}
	else
	{
		//bad
		log("create_surf_from_path() error: " << IMG_GetError());
	}
	return temp;
}

SDL_Texture* ss::sdl_::create_text(SDL_Renderer* _rend, Uint32 _format, int _access, int _w, int _h) const
{
	// format can be whole lot of things...
	// 
	// access
	// SDL_TEXTUREACCESS_STATIC changes rarely, not lockable
	// SDL_TEXTUREACCESS_STREAMING changes frequently, lockable
	// SDL_TEXTUREACCESS_TARGET can be used as a render target

	// w width
	// h height

	SDL_Texture* text = nullptr;

	SDL_ClearError();
	text = SDL_CreateTexture(_rend, _format, _access, _w, _h);
	if (text)
	{
		log("create_text(): " << text);
		//return text;
	}
	else
	{
		log("create_text() error: " << SDL_GetError());
		//return nullptr;
	}
	return text;
}

SDL_Texture* ss::sdl_::create_text_from_surf(SDL_Renderer* _rend, SDL_Surface* _surf) const
{
	SDL_Texture* t = nullptr;

	t = SDL_CreateTextureFromSurface(_rend, _surf);
	if (t)
	{
		//good
		log("create_text_from_surf(): " << t);
		//return t;
	}
	else
	{
		//bad
		log("create_text_from_surf(" << _rend << ", " << _surf << ") error: " << SDL_GetError());
		//return nullptr;
	}
	return t;
}

SDL_Texture* ss::sdl_::create_text_from_path(SDL_Renderer* _rend, char const* _path) const
{
	SDL_Surface* temp_s = nullptr;
	SDL_Texture* temp_t = nullptr;

	temp_s = create_surf_from_path(_path);
	if (temp_s)
	{
		//surface created
		temp_t = create_text_from_surf(_rend, temp_s);
		uint8_t r = destroy_surf(temp_s);

		if (temp_t)
		{
			//  good
			log("create_text_from_path(" << _path << "): " << temp_t);
		}
		else
		{
			// bad
			log("create_text_from_path() failed to create texture: " << _path);
		}
	}
	else
	{
		//surface not created
		log("create_surf_from_path() failed to create surface: " << _path);
	}

	return temp_t;
}

int ss::sdl_::draw()
{
	SDL_RenderClear(Rend_);

	int r = rend_cpy(Rend_, Texture_, NULL, NULL);
	if (r) return r;
	//switch (r)
	//{
	//case -1:
	//	break;
	//default:
	//	break;
	//}

	//qSDL_UpdateWindowSurface(Win_);
	SDL_RenderPresent(Rend_);

	return r;
}

int ss::sdl_::set_rend_targ(SDL_Renderer* _r, SDL_Texture* _t) const
{
	SDL_GetError();
	int r = SDL_SetRenderTarget(_r, _t);
	if (r)
	{
		//bad
		log("set_rend_targ(" << _r << ", " << _t << ") error: " << SDL_GetError());
	}
	else
	{
		//good
		log("set_rend_targ(" << _r << ", " << _t << ")");
	}
	return r;
}

int32_t ss::sdl_::get_pixel_format(SDL_RendererInfo* _ri) const
{
	//int n = _ri->num_texture_formats;
	//Uint32 u = 0;

	//for (int i=0; i<n;++i)
	//{
	//	u = _ri->texture_formats[i];
	//}
	//
	//return u;
	return _ri->texture_formats[0];
}

int ss::sdl_::get_rend_info(SDL_Renderer* _r, SDL_RendererInfo* _ri) const
{
	//int SDL_GetRendererInfo(SDL_Renderer * renderer,
	//	SDL_RendererInfo * info)
	int r = SDL_GetRendererInfo(_r, _ri);
	if (r)
	{
		//bad
		log("get_rend_info() error: " << SDL_GetError());
	}
	else
	{
		//good
		log("get_rend_info()");
	}
	return r;
}

int ss::sdl_::query_text(SDL_Texture* _text, Uint32* _format, int* _access, int* _w, int* _h) const
{
	//int SDL_QueryTexture(SDL_Texture * texture,
	//	Uint32 * format, int* access,
	//	int* w, int* h);

	int r = -1;

	SDL_ClearError();
	r = SDL_QueryTexture(_text, _format, _access, _w, _h);
	if (r)
	{
		//bad
		log("query_text(" <<
			_text << ", " <<
			_format << ", " <<
			_access << ", " <<
			_w << ", " << _h <<
			") error: " << SDL_GetError());
	}
	else
	{
		//good
		log("query_text()");
	}
	return r;
}

int ss::sdl_::rend_cpy(SDL_Renderer* _rend, SDL_Texture* _text, SDL_Rect const* _src, SDL_Rect const* _dst) const
{
	SDL_ClearError();
	int r = SDL_RenderCopy(_rend, _text, _src, _dst);
	if (r)
	{
		// bad
		log("rend_cpy(" << _rend << ", " << _text << ", " << _src << ", " << _dst << ") error: " << SDL_GetError());
	}
	else
	{
		//good
		log("rend_cpy(" << _text << ")");
	}

	return r;
}

uint8_t ss::sdl_::destroy()
{
	int8_t  r = -1;

	//r = destroy_text(buffer[0]);
	//r = destroy_text(buffer[1]);
	r = destroy_surf(Surface_);
	r = destroy_text(Texture_);
	r = destroy_rend(Rend_);
	r = destroy_win(Win_);
	r = destroy_sdl_image();
	r = destroy_sdl_video();
	r = destroy_sdl(); // not sure where to put destroy_sdl() really...

	return 0x0;
}

uint8_t ss::sdl_::destroy_win(SDL_Window* _w) const
{
	SDL_ClearError();
	SDL_DestroyWindow(_w);
	std::string s = SDL_GetError();
	if (s == "")
	{
		// good
		log("destroy_win(" << _w << ")");
		return 0x0;
	}
	else
	{
		// bad
		log("destroy_win error: " << s);
		return 0xF;
	}
}

uint8_t ss::sdl_::destroy_rend(SDL_Renderer* _r) const
{
	SDL_ClearError();
	SDL_DestroyRenderer(_r);
	std::string s = SDL_GetError();
	if (s == "")
	{
		// good
		log("destroy_rend(" << _r << ")");
		return 0x0;
	}
	else
	{
		// bad
		log("destroy_rend(" << _r << ") error: " << s);
		return 0xFF;
	}
}

uint8_t ss::sdl_::destroy_text(SDL_Texture* _t) const
{
	SDL_ClearError();
	SDL_DestroyTexture(_t);
	std::string s = SDL_GetError();
	if (s == "")
	{
		// good
		log("destroy_text(" << std::hex << (int32_t)_t << ")");
		return 0x0;
	}
	else
	{
		// bad
		log("destroy_text(" << _t << ") error: " << s);
		return 0xF;
	}
}

uint8_t ss::sdl_::destroy_surf(SDL_Surface* _s) const
{
	// safe to pass null to

	SDL_ClearError();
	SDL_FreeSurface(_s);
	std::string r = SDL_GetError();
	if (r == "")
	{
		log("destroy_surf(" << _s << ")");
		return 0x0;
	}
	else
	{
		log("destroy_surf(" << _s << ") error: " << r);
		return 0xF;
	}
}

uint8_t ss::sdl_::destroy_sdl() const
{
	SDL_ClearError();
	SDL_Quit();
	std::string s = SDL_GetError();
	if (s == "")
	{
		//good
		log("destroy_sdl() " << s);
		return 0x0;
	}
	else
	{
		//bad
		log("SDL_Quit error: " << s);
		return 0xF;
	}
}

uint8_t ss::sdl_::destroy_sdl_video() const
{
	SDL_ClearError();
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	std::string s = SDL_GetError();
	if (s == "")
	{
		//good
		log("destroy_sdl_video() " << s);
		return 0x0;
	}
	else
	{
		//bad
		log("SDL video error: " << s);
		return 0xF;
	}
}

uint8_t ss::sdl_::destroy_sdl_image() const
{
	std::string s = IMG_GetError();
	IMG_Quit();
	s = IMG_GetError();
	if (s == "")
	{
		//good
		log("destroy_sdl_image() " << s);
		return 0x0;
	}
	else
	{
		//bad
		log("SDL image error: " << s);
		return 0xF;
	}
}

