#pragma once

#include "ALL.h"

#include "SDP.h"

#include "ViewController.h"

#include "STengMenu.h"

#include "TextResManager.h"
//#include "Asset_Mgr.h"
//#include "View_Asset.h"

//#include "Quick_Sort.h"

namespace ss
{
	class Engine :
		public State_Holder
	{
	public:
		// BEGIN	state_holder inherits
		
		//virtual uint8_t pop_state();
		//virtual uint8_t push_state(state*);

		//virtual uint8_t enter_state() const;
		//virtual uint8_t pause_state() const;
		//virtual uint8_t resume_state() const;
		//virtual uint8_t exit_state() const;

		//virtual uint8_t input_state() const;
		//virtual uint8_t draw_state() const;

		//std::stack<state*> Stack_;
		
		// END		state_holder inherits


		Engine()
		{
			log("Engine()");
			rt ret = init();
			log("Engine::init() ret: " << c2m(ret));
		}
		~Engine()
		{
			log("~Engine()");
			rt ret = destroy();
			log("Engine::destroy() ret: " << c2m(ret));
		}

		// engine() functions
		rt init();
		rt init_locals();
		rt destroy();

		// view controller
		ViewController View_;


		// input controller
		
		// audio controller
		
		// texture resource manager
		TextResManager	TRM_;

		// class engine states
		ST_eng_menu ST_em_;

		// game loop
		rt loop();
		rt input();
		rt draw();
		bool On_;


	}; // END	engine class
} // END ss
