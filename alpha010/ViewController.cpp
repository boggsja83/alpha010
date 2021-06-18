#include "ViewController.h"

ss::rt ss::ViewController::init()
{
	rt ret = rt::INITIAL;
	rt rr = rt();
	//int reti = -1;

	log("ViewController::init()");

	ret = init_locals();
	if (ret!=rt::SUCCESS) { return ret; }

	ret = init_sdl_video();
	if (ret != rt::SUCCESS) { return ret; }

	ret = init_sdl_img();
	if (ret != rt::SUCCESS) { return ret; }

	Win_ = create_win(title_win, x_win, y_win, width_win, height_win, flags_win);
	if (!Win_) return rt::FAIL_CREATE_WIN;

	Rend_ = create_rend(Win_, index_rend, flags_rend);
	if (!Rend_) return rt::FAIL_CREATE_REND;

	// draw window surface (red)
	Surface_ = get_win_surf(Win_);
	SDL_FillRect(Surface_, &rect_win,
		SDL_MapRGB(Surface_->format, r_surf, g_surf, b_surf));
	ret = update_win_surf(Win_);
	if (ret != rt::SUCCESS) { return ret; }

	// set renderer color (green)
	ret = set_rend_draw_color(Rend_, r_rend, g_rend, b_rend, a_rend);
	if (ret != rt::SUCCESS) { return ret; }

	// set renderer info
	ret = get_rend_info(Rend_, &info_rend);
	if (ret != rt::SUCCESS) { return ret; }

	// set pixel format
	pixel_format_rend = get_pixel_format(&info_rend);

	// create texture
	Texture_ = create_text(Rend_, pixel_format_rend, text_access_target, rect_win.w, rect_win.h);
	if (!Texture_) return rt::FAIL_CREATE_TEXT;

	return ret;
}

ss::rt ss::ViewController::init_locals()
{
	log("ViewController::init_locals()");
	Win_		= nullptr;
	Rend_		= nullptr;
	Texture_	= nullptr;
	Surface_	= nullptr;

	return rt();
}

ss::rt ss::ViewController::destroy()
{
	rt ret = rt::INITIAL;

	log("ViewController::destroy()");
	
	ret = destroy_surf(Surface_);//dont need this.  this surface will be deleted from win_ automatically (right now because how i have it, Surface_ is "created"by get_win_surf(...))
	ret = destroy_text(Texture_);
	ret = destroy_rend(Rend_);
	ret = destroy_win(Win_);
	ret = destroy_sdl_image();
	ret = destroy_sdl_video();
	ret = destroy_sdl();

	return ret;
}
