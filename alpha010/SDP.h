#pragma once
// State Design Pattern

#include "Logger.h"

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
			log("state");
		}
		~state()
		{
			log("~state");
		}

		//virtual uint8_t init() = 0;
		//virtual uint8_t destroy() = 0;

		virtual uint8_t enter()	 const = 0;
		virtual uint8_t pause()	 const = 0;
		virtual uint8_t resume() const = 0;
		virtual uint8_t exit()	 const = 0;
								 
		virtual uint8_t draw()	 const = 0;
		virtual uint8_t input()	 const = 0;
	};	// END state

	class state_holder
	{
	private:
	public:
		state_holder()
		{
			log("state_holder()");
			uint8_t r = init();
		}
		~state_holder()
		{
			log("~state_holder()");
			uint8_t r = destroy();
		}

		// general state functions
		virtual uint8_t pop_state();
		virtual uint8_t push_state(state*);

		virtual uint8_t enter_state() const;
		virtual uint8_t pause_state() const;
		virtual uint8_t resume_state() const;
		virtual uint8_t exit_state() const;

		// specific state functions for this project
		virtual uint8_t input_state() const;//??
		virtual uint8_t draw_state() const;//??

		//d::array<state, MAX_STATE_STACK_SIZE> Stack_;
		std::stack<state*> Stack_;
		uint8_t init();
		uint8_t destroy();
	};
}	// END	state_mgr
