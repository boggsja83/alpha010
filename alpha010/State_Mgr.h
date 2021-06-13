#pragma once

#include "Logger.h"
#include "SDP.h"

#include "ST_STMGR_Eng_Menu.h"


namespace ss
{
	// this class will hold instances of needed states
	// is a state_holder itself
	// the states this hold simply contains
	// the state instances needed at that time
	// i.e. class st_stmgr_lvl1 holds
	//	all states needed during level 1
	class state_mgr :
		public state_holder
	{
	public:

		// BEGIN state_holder inherits
		
		//virtual uint8_t pop_state();
		//virtual uint8_t push_state(state*);

		//virtual uint8_t enter_state() const;
		//virtual uint8_t pause_state() const;
		//virtual uint8_t resume_state() const;
		//virtual uint8_t exit_state() const;

		//virtual uint8_t input_state() const;
		//virtual uint8_t draw_state() const;

		//std::stack<state*> Stack_;
		
		// END	state_holder inherits

		state_mgr()
		{
			log("state_mgr()");
			uint8_t r = init();
		}
		~state_mgr()
		{
			log("~state_mgr()");
			uint8_t r = destroy();
		}

		uint8_t init();
		uint8_t destroy();

		st_stmgr_eng_menu eng_menu;
	}; // END	class state_mgr
} // END	namespace ss
