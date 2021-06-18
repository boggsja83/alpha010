#include "SDP.h"

ss::rt ss::state_holder::pop_state()
{
	rt ret = rt::INITIAL;

	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }

	ret = Stack_.top()->exit();
	if (ret!=rt::SUCCESS) { return ret; }

	Stack_.pop();
		
	if (!Stack_.empty()) { ret = Stack_.top()->resume(); }
		
	return ret;
}

ss::rt ss::state_holder::push_state(state* _state)
{
	rt ret = rt::INITIAL;

	if(!Stack_.empty())
	{
		ret = Stack_.top()->pause();
		if (ret!=rt::SUCCESS) { return ret; }
	}

	Stack_.push(_state);

	return Stack_.top()->enter();
}

ss::rt ss::state_holder::enter_state() const
{
	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }
	return Stack_.top()->enter();
}

ss::rt ss::state_holder::pause_state() const
{
	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }
	return Stack_.top()->pause();
}

ss::rt ss::state_holder::resume_state() const
{
	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }
	return Stack_.top()->resume();
}

ss::rt ss::state_holder::exit_state() const
{
	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }
	return Stack_.top()->exit();
}

ss::rt ss::state_holder::input_state() const
{
	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }
	return Stack_.top()->input();
}

ss::rt ss::state_holder::draw_state() const
{
	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }
	return Stack_.top()->draw();
}

ss::rt ss::state_holder::init()
{
	return rt();
}

ss::rt ss::state_holder::destroy()
{
	return rt();
}
