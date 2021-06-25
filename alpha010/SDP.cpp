#include "SDP.h"

ss::rt ss::State_Holder::pop_state()
{
	rt ret = rt::INITIAL;

	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }

	ret = Stack_.top()->exit();
	if (ret!=rt::SUCCESS) { return ret; }

	Stack_.pop();
		
	if (!Stack_.empty()) { ret = Stack_.top()->resume(); }
		
	return ret;
}

ss::rt ss::State_Holder::push_state(State* _state)
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

ss::rt ss::State_Holder::enter_state() const
{
	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }
	return Stack_.top()->enter();
}

ss::rt ss::State_Holder::pause_state() const
{
	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }
	return Stack_.top()->pause();
}

ss::rt ss::State_Holder::resume_state() const
{
	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }
	return Stack_.top()->resume();
}

ss::rt ss::State_Holder::exit_state() const
{
	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }
	return Stack_.top()->exit();
}

ss::rt ss::State_Holder::input_state() const
{
	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }
	return Stack_.top()->input();
}

ss::rt ss::State_Holder::draw_state() const
{
	if (Stack_.empty()) { return rt::STATE_STACK_EMPTY; }
	return Stack_.top()->draw();
}

ss::rt ss::State_Holder::init()
{
	return rt();
}

ss::rt ss::State_Holder::destroy()
{
	return rt();
}
