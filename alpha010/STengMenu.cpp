#include "STengMenu.h"

/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::enter()
/*--------------------------------------------------*/
{
	log("ST_eng_menu::enter()");

	rt ret = rt::INITIAL;

	ret = TRL_.load_all_text();
	if (ret != rt::OK) return ret;

	return ret;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::pause()
/*--------------------------------------------------*/
{
	log("ST_eng_menu::pause()");
	return rt();
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::resume()
/*--------------------------------------------------*/
{
	log("ST_eng_menu::resume()");
	return rt();
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::exit()
/*--------------------------------------------------*/
{
	log("ST_eng_menu::exit()");

	rt ret = rt::INITIAL;

	ret = TRL_.delete_list();
	if (ret != rt::OK)return ret;

	return ret;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::input()
/*--------------------------------------------------*/
{
	//log("ST_eng_menu::input()");
	
	//SDL_PollEvent(&ev);

	SDL_Event ev = Input_->poll_event();

	switch (ev.type)
	{
	case SDL_QUIT:
		return rt::QUIT;
		break;
	case SDL_KEYDOWN:
		break;
	case SDL_KEYUP:
		if (ev.key.keysym.scancode == SDL_SCANCODE_Q) { return rt::QUIT; }
		if (ev.key.keysym.scancode == SDL_SCANCODE_SPACE) return rt::INPUT_RECEIVED;
		break;
	default:
		break;
	}

	return rt::OK;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::draw()
/*--------------------------------------------------*/
{
	//log("ST_eng_menu::draw()");

	rt ret = rt::INITIAL;
	SDL_RenderClear(Rend_);
	ret = rend_cpy(Rend_, TRL_.get_text(text_name), NULL, NULL);
	SDL_RenderPresent(Rend_);
	
	//TRL_.delete_all_text();
	//TRL_.load_all_text();

	return ret;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::init()
/*--------------------------------------------------*/
{
	log("ST_eng_menu::init()");
	
	Rend_ = nullptr;
	
	return rt::OK;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::destroy()
/*--------------------------------------------------*/
{
	log("ST_eng_menu::destroy()");
	return rt();
}
