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
	
	ret = Input_->input(ICA_);


	return ret;

	//SDL_Event ev;
	//SDL_PollEvent(&ev);

	//switch (ev.type)
	//{
	//case SDL_QUIT:
	//	return rt::QUIT;
	//	break;
	//case SDL_KEYDOWN:
	//	break;
	//case SDL_KEYUP:
	//	if (ev.key.keysym.scancode == SDL_SCANCODE_Q) { return rt::QUIT; }
	//	if (ev.key.keysym.scancode == SDL_SCANCODE_SPACE) return rt::INPUT_RECEIVED;
	//	break;
	//default:
	//	break;
	//}

	//return rt::OK;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::draw()
/*--------------------------------------------------*/
{
	//log("ST_eng_menu::draw()");

	rt ret = rt::INITIAL;
	SDL_RenderClear(View_->rend());
	ret = rend_cpy(View_->rend(), TRL_.get_text(Name_tex_), NULL, NULL);
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
	// init ArrIC function
	//for (InputContext ic : ICA_)
	//{
	//	ic = IC::NONE;
	//}
	//for (ICV icv_ : ICD_.ICVvec_)
	//{
	//}

	//for (size_t i=0; i<ICD_.ICVvec_.size();++i)
	//{
	//	ICA_[i] = 
	//}
	

	// add all InputContext's from this "level"
	// to the InputContextArray
	ICA_[0] = IC_;
	ICA_[1] = IC::TEST1;

	return rt::OK;
}
/*--------------------------------------------------*/
ss::rt ss::ST_eng_menu::destroy()
/*--------------------------------------------------*/
{
	log("ST_eng_menu::destroy()");
	return rt();
}
