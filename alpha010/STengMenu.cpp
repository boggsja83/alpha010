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

	IRAO irao({});
	ret = Input_->input(ICA_,irao);


	ICD temp_icd = Input_->get_icd(testing.ic());
	ICV temp_icv = ICV::NONE;

	for (size_t i = 0; i < irao.size(); ++i)
	{
		if (irao[i])
		{
			temp_icv = static_cast<ICV>(i);
		
		//if context is in ... definition. object.input(ICV)
			if (Input_->icd_contains_icv(temp_icd, temp_icv))
			{
				ret = testing.input_rx(temp_icv);
			}
		}
	}

	return ret;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::draw()
/*--------------------------------------------------*/
{
	//log("ST_eng_menu::draw()");

	rt ret = rt::INITIAL;

	SDL_Rect temp_r(rect_win);
	size_t w=temp_r.w, h=temp_r.h, x=temp_r.x, y=temp_r.y;

	temp_r.x = (w - x) / 2 -w / 4;
	temp_r.y = (h - y) / 2 -h / 4;
	temp_r.w = w/2;
	temp_r.h = h/2;

	//temp_r = cube_to_sdl_r(testing.get_rect());
	
	SDL_RenderClear(View_->rend());
	ret = rend_cpy(View_->rend(), TRL_.get_text(Name_text_), NULL, NULL);
	ret = rend_cpy(View_->rend(), TRL_.get_text(testing.text_name()), NULL, testing.get_rect());
	SDL_RenderPresent(View_->rend());
	
	//TRL_.delete_all_text();
	//TRL_.load_all_text();

	return ret;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::init()
/*--------------------------------------------------*/
{
	log("ST_eng_menu::init()");
	
	// init locals function needed here
	View_ = nullptr;
	Input_ = nullptr;
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
