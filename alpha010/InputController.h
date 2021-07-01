#pragma once

#include "ALL.h"
#include "SDLwrapper.h"

/*--------------------------------------------------*/
namespace ss
/*--------------------------------------------------*/
{

/*
	Level 1		Raw Input
	Level 2		Convert Raw Input to Context Input
	Level 3		High-level Context Input handling
*/

/*--------------------------------------------------*/
	class InputController
/*--------------------------------------------------*/
	{
		/*--------------------------------------------------*/
		/*--------------Constructor/Destructor--------------*/
		/*--------------------------------------------------*/
	public:
		/*--------------------------------------------------*/
		InputController() 
		/*--------------------------------------------------*/
		{ 
			log("InputController()");
			rt ret = init();
		}
		/*--------------------------------------------------*/
		~InputController() 
		/*--------------------------------------------------*/
		{
			log("~InputController()");
			rt ret = destroy();
		}
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*-----------------Init/Destroy---------------------*/
		/*--------------------------------------------------*/
	private:
		rt init();
		rt destroy();
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*----------------Member functions------------------*/
		/*--------------------------------------------------*/
	public:
		SDL_Event poll_event();
		rt input();
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*----------------Member variables------------------*/
		/*--------------------------------------------------*/
	private:
		SDL_Event Event_;
		/*--------------------------------------------------*/


	}; // END	class InputController
} // END	namespace ss

