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
	if (ret != rt::OK) return ret;

	return ret;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::input()
/*--------------------------------------------------*/
{
	//log("ST_eng_menu::input()");
	
	rt ret = rt::INITIAL;

	//Flags_IR	irao({});//delete this system, using IRT instead
	ArrIRT		irta;

	ret = Input_->input(ICD_, irta);
	
	if(ret == rt::INPUT_RECEIVED)
		for (size_t i = 0; i < irta.size(); ++i)
			if(irta[i].IC_ == testing.ic())
				testing.input_rx(irta[i]);

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
						TRL_.get_text(NameText_), 
						NULL, NULL);
	ret = rend_cpy(		View_->rend(), 
						TRL_.get_text(testing.text_name()), 
						NULL, testing.get_rect());
	SDL_RenderPresent(	View_->rend());
	
	return ret;
}
ss::rt ss::ST_eng_menu::update()
{
	//log("ST_eng_menu::update()");
	return testing.update();
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::init()
/*--------------------------------------------------*/
{
	log("ST_eng_menu::init()");
	
	// init locals function needed here
	//View_ = nullptr;
	//Input_ = nullptr;
	//IC_ = IC::MENU;

	// add all InputContext's from this "level"
	// to the InputContextArray
	//ICD_[0] = IC_;//this levels IC_
	//ICD_[1] = IC::TEST1;// additional IC
	//ICD_[2] = testing.ic();// addition IC (Object testing)


	ICD_[0] = ICD_em;	//this objects IC
	ICD_[1] = ICD_t1;
	ICD_[2] = ICD_t2;

	return rt::OK;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::destroy()
/*--------------------------------------------------*/
{
	log("ST_eng_menu::destroy()");
	return rt();
}
