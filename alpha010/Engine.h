#pragma once

#include "Logger.h"

#include "SDL_.h"
#include "SDP.h"

#include "ST_ENG_Menu.h"

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
			uint8_t r = init();
		}
		~engine()
		{
			log("~engine()");
			uint8_t r = destroy();
		}

		// engine() functions
		uint8_t init();
		uint8_t init_locals();
		uint8_t destroy();

		// view controller
		sdl_ sdl_inst;

		// input controller
		
		// audio controller
		
		// game loop
		uint8_t loop();
		uint8_t input();
		uint8_t draw();
		bool On_;

		// asset manager

		// class engine states
		st_eng_menu st_em;

		// return types
		uint8_t ret_;

	}; // END	engine class
} // END ss
