#include "InputController.h"

/*--------------------------------------------------*/
ss::rt ss::InputController::init()
/*--------------------------------------------------*/
{
	log("InputController::init()");
	rt ret = rt::INITIAL;

	// init_locals()

	ret = init_sdl_input();
	if (ret != rt::OK) return ret;

	return ret;
}
/*--------------------------------------------------*/
ss::rt ss::InputController::destroy()
/*--------------------------------------------------*/
{
	log("InputController::destroy()");
	rt ret = rt::INITIAL;

	ret = destroy_sdl_input();
	if (ret != rt::OK) return ret;

	return ret;
}
///*--------------------------------------------------*/
//SDL_Event ss::InputController::poll_event()
///*--------------------------------------------------*/
//{
//	//delete this function
//	
//
//	while (SDL_PollEvent(&Event_))
//	{
//		log("poll_event()");
//
//	}
//	//log("done polling");
//	//if (SDL_PollEvent(&Event_))
//	//	return rt::EVENT_PENDING;
//	//else
//	//	return rt::EVENT_NOT_PENDING;
//
//	return Event_;
//}

ss::rt ss::InputController::input()
{
	
	/*
	PollEvents

	*/
	SDL_Event temp_e;
	bool waiting = true;
	ET_.clear();
	
	while(SDL_PollEvent(&temp_e))
	{
		log("InputController::input() processing event: " << temp_e.type);
		
		ET_.push_back(temp_e.type);
		waiting = false;

		switch(temp_e.type)
		{
			case SDL_QUIT:
				return rt::QUIT;
				break;
			case SDL_KEYDOWN:
				return rt::INPUT_RECEIVED;
				break;
			case SDL_KEYUP:
				break;
			default:
			break;
		}

		
	}

	if(!waiting){ log("InputController::input() done processing "<<ET_.size()<<" events"); }

	return rt::OK;
}
