#pragma once

#include <vector>
#include <array>
#include <map>
#include <tuple>

#include "ALL.h"
#include "SDLwrapper.h"

#include "InputContext.h"
#include "ControlMap.h"

/*--------------------------------------------------*/
namespace ss
/*--------------------------------------------------*/
{
	typedef std::array<InputContext, static_cast<size_t>(IC::IC_COUNT)> ArrIC;
/*
	Level 1		Raw Input
	Level 2		Convert Raw Input to Context Input
	-calling function provides list of Contexts
	-broadcast
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
		//delete poll_event function
		//SDL_Event poll_event();

		rt input(ArrIC&);
	
	private:
		
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*----------------Member variables------------------*/
		/*--------------------------------------------------*/
	private:

		//std::vector<Uint32>	ET_;
		// 
		// actual highest value is 282? i believe
		std::array<bool, 300> KSprev_;



		// take event map stuff out but put it in another file to save
		//rt init_event_map();
		//std::map<SDL_EventType, char const*> EventMap_;

		/*--------------------------------------------------*/


	}; // END	class InputController
} // END	namespace ss

