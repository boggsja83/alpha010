#include "SDP.h"

uint8_t ss::state_holder::pop_state()
{
	uint8_t r = 0xFF;

	if (Stack_.empty()) { return r; }

	r = Stack_.top()->exit();
	if (r) { return r; }

	Stack_.pop();
		
	if (!Stack_.empty()) { r = Stack_.top()->resume(); }
		
	return r;
}

uint8_t ss::state_holder::push_state(state* _state)
{
	uint8_t r = 0xFF;

	if(!Stack_.empty())
	{
		r = Stack_.top()->pause();
		if (r) { return r; }
	}

	Stack_.push(_state);

	return Stack_.top()->enter();
}

uint8_t ss::state_holder::enter_state() const
{
	if (Stack_.empty()) { return 0xFF; }
	return Stack_.top()->enter();
}

uint8_t ss::state_holder::pause_state() const
{
	if (Stack_.empty()) { return 0xFF; }
	return Stack_.top()->pause();
}

uint8_t ss::state_holder::resume_state() const
{
	if (Stack_.empty()) { return 0xFF; }
	return Stack_.top()->resume();
}

uint8_t ss::state_holder::exit_state() const
{
	if (Stack_.empty()) { return 0xFF; }
	return Stack_.top()->exit();
}

uint8_t ss::state_holder::input_state() const
{
	if (Stack_.empty()) { return 0xFF; }
	return Stack_.top()->input();
}

uint8_t ss::state_holder::draw_state() const
{
	if (Stack_.empty()) { return 0xFF; }
	return Stack_.top()->draw();
}

uint8_t ss::state_holder::init()
{
	return uint8_t();
}

uint8_t ss::state_holder::destroy()
{
	return uint8_t();
}
