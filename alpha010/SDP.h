#pragma once
// State Design Pattern

#include "ALL.h"

#include <stack>

namespace ss
{
	// if using this externally, declare extern const uint8_t MAX_...
	// static needed?
	static const uint8_t MAX_STATE_STACK_SIZE = 10;

	class state
	{
	private:
	public:
		state()
		{
			log("state()");
		}
		~state()
		{
			log("~state()");
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

	class state_holder
	{
	private:
	public:
		state_holder()
		{
			log("state_holder()");
			rt ret = init();
		}
		~state_holder()
		{
			log("~state_holder()");
			rt ret = destroy();
		}

		// general state functions
		virtual rt pop_state();
		virtual rt push_state(state*);

		virtual rt enter_state() const;
		virtual rt pause_state() const;
		virtual rt resume_state() const;
		virtual rt exit_state() const;

		// specific state functions for this project
		virtual rt input_state() const;//??
		virtual rt draw_state() const;//??

		//d::array<state, MAX_STATE_STACK_SIZE> Stack_;
		std::stack<state*> Stack_;
		rt init();
		rt destroy();
	};
}	// END	state_mgr
