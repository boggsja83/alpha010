#pragma once
// State Design Pattern

#include "ALL.h"

#include <stack>

namespace ss
{
	// if using this externally, declare extern const uint8_t MAX_...
	// static needed?
	//static const uint8_t MAX_STATE_STACK_SIZE = 10;

	class State
	{
	private:
	public:
		State()
		{
			log("State()");
		}
		~State()
		{
			log("~State()");
		}

		//virtual uint8_t init() = 0;
		//virtual uint8_t destroy() = 0;

		virtual rt enter()	 = 0;
		virtual rt pause()	 = 0;
		virtual rt resume() = 0;
		virtual rt exit()	 = 0;
								 
		virtual rt draw()	 = 0;
		virtual rt input()	 = 0;
	};	// END state

	class State_Holder
	{
	private:
	public:
		State_Holder()
		{
			log("State_Holder()");
			rt ret = init();
		}
		~State_Holder()
		{
			log("~State_Holder()");
			rt ret = destroy();
		}

		// general state functions
		virtual rt pop_state();
		virtual rt push_state(State*);

		virtual rt enter_state();
		virtual rt pause_state();
		virtual rt resume_state();
		virtual rt exit_state();

		// specific state functions for this project
		virtual rt input_state();//??
		virtual rt draw_state();//??

		//d::array<state, MAX_STATE_STACK_SIZE> Stack_;
		std::stack<State*> Stack_;
		rt init();
		rt destroy();
	};
}	// END	state_mgr
