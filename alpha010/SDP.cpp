#include "SDP.h"

uint8_t ss::state_holder::pop_state()
{
	if (Stack_.empty())
	{
		// no states on Stack_
		return 0xFF;
	}
	else
	{
		// at least one state on Stack_
		(Stack_.size() - 1);

	}
	return uint8_t();
}

uint8_t ss::state_holder::push_state(const state* _state)
{
	return uint8_t();
}

uint8_t ss::state_holder::enter_state()
{
	return uint8_t();
}

uint8_t ss::state_holder::pause_state()
{
	return uint8_t();
}

uint8_t ss::state_holder::resume_state()
{
	return uint8_t();
}

uint8_t ss::state_holder::exit_state()
{
	return uint8_t();
}

uint8_t ss::state_holder::input_state()
{
	return uint8_t();
}

uint8_t ss::state_holder::draw_state()
{
	return uint8_t();
}
