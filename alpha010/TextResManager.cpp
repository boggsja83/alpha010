#include "TextResManager.h"

ss::rt ss::TextResManager::load_tr(SDL_Renderer* _rend, TextRes& _tr)
{
	int8_t iret = find_tr(&_tr);
	rt ret = rt::INITIAL;
	SDL_Texture* temp_t = nullptr;

	if (iret == rerr8)
	{
		//not already in list
		temp_t = create_text_from_path(_rend, _tr.path());
		if (!temp_t) { return rt::FAIL_CREATE_TEXT; }
		
		//set TextRes text
		_tr.text(temp_t);

		//add to list
		TextRes_.push_back(_tr);
	}
	else
	{
		//already in list
		//set ITextRes text
		//_tr.text(get_tr(iret)->text());
		return rt::ALREADY_IN_LIST;
	}

	return rt::SUCCESS;
}

int8_t ss::TextResManager::find_tr_p(char const*) const
{
	return int8_t();
}

int8_t ss::TextResManager::find_tr_n(char const* _s) const
{
	for (size_t i = 0; i < TextRes_.size(); ++i)
		if (_s == TextRes_[i].name())
			return static_cast<int8_t>(i);
	return rerr8;
}

int8_t ss::TextResManager::find_tr(TextRes* _tr) const
{
	for (size_t i=0; i<TextRes_.size(); ++i)
		if (*_tr == TextRes_[i])
			return static_cast<int8_t>(i);
	return rerr8;
}

ss::rt ss::TextResManager::init()
{
	//MAX_TEXT_RES = 10;
	TextRes_.reserve(MAX_TEXT_RES);
	return rt::SUCCESS;
}

ss::rt ss::TextResManager::destroy()
{
	return rt();
}
