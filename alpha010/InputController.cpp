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
/*--------------------------------------------------*/
SDL_Event ss::InputController::poll_event()
/*--------------------------------------------------*/
{
	while (SDL_PollEvent(&Event_))
	{
		log("poll_event()");

	}
	//log("done polling");
	//if (SDL_PollEvent(&Event_))
	//	return rt::EVENT_PENDING;
	//else
	//	return rt::EVENT_NOT_PENDING;

	return Event_;
}

ss::rt ss::InputController::input()
{
	return rt();
}
