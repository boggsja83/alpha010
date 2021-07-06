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
	
	rt ret = rt::INITIAL;

	Flags_IR irao({});

	ret = Input_->input(ICA_,irao);
	testing.input_rx(irao);

	return ret;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::draw()
/*--------------------------------------------------*/
{
	//log("ST_eng_menu::draw()");

	rt ret = rt::INITIAL;

	SDL_RenderClear(	View_->rend());
	ret = rend_cpy(		View_->rend(), 
						TRL_.get_text(Name_text_), 
						NULL, NULL);
	ret = rend_cpy(		View_->rend(), 
						TRL_.get_text(testing.text_name()), 
						NULL, testing.get_rect());
	SDL_RenderPresent(	View_->rend());
	
	return ret;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::init()
/*--------------------------------------------------*/
{
	log("ST_eng_menu::init()");
	
	// init locals function needed here
	//View_ = nullptr;
	//Input_ = nullptr;
	IC_ = IC::MENU;

	// add all InputContext's from this "level"
	// to the InputContextArray
	ICA_[0] = IC_;//this levels IC_
	ICA_[1] = IC::TEST1;// additional IC
	ICA_[2] = testing.ic();// addition IC (Object testing)

	return rt::OK;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::destroy()
/*--------------------------------------------------*/
{
	log("ST_eng_menu::destroy()");
	return rt();
}
