#pragma once
// State Design Pattern

#include "Logger.h"

#include <array>

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

		virtual uint8_t enter() =0 ;
		virtual uint8_t pause() = 0;
		virtual uint8_t resume() = 0;
		virtual uint8_t exit() = 0;

		virtual uint8_t input() = 0;
		virtual uint8_t draw() = 0;
	};	// END state

	class state_holder
	{
	private:
	public:
		state_holder()
		{
			log("state_holder()");
		}
		~state_holder()
		{
			log("~state_holder()");
		}

		virtual uint8_t pop_state();
		virtual uint8_t push_state(const state*);

		virtual uint8_t enter_state();
		virtual uint8_t pause_state();
		virtual uint8_t resume_state();
		virtual uint8_t exit_state();

		virtual uint8_t input_state();//??
		virtual uint8_t draw_state();//??

		std::array<state, MAX_STATE_STACK_SIZE> Stack_;
	};
}	// END	state_mgr
