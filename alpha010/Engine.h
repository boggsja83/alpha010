#pragma once

#include "ALL.h"

#include "SDP.h"

#include "ViewController.h"

#include "STengMenu.h"

//#include "Asset_Mgr.h"
//#include "View_Asset.h"

//#include "Quick_Sort.h"

namespace ss
{
	class engine :
		public state_holder
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


		engine()
		{
			log("engine()");
			rt ret = init();
		}
		~engine()
		{
			log("~engine()");
			rt ret = destroy();
		}

		// engine() functions
		rt init();
		rt init_locals();
		rt destroy();

		// view controller
		//sdl_ sdl_inst;
		ViewController View_;


		// input controller
		
		// audio controller
		
		// game loop
		rt loop();
		rt input();
		rt draw();
		bool On_;

		// asset manager

		// class engine states
		st_eng_menu st_em;

		// return types
		//uint8_t ret_;

	}; // END	engine class
} // END ss
