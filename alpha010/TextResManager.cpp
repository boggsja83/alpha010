#include "TextResManager.h"

ss::rt ss::TextResManager::push_tr(TextRes& _tr)
{
	log("TextResManager::push_tr("<<&_tr<<")");
	int8_t iret = find_tr(&_tr);
	rt ret = rt::INITIAL;
	SDL_Texture* temp_t = nullptr;

	if (iret == rerr8)
	{
		//not already in list
		temp_t = create_text_from_path(Rend_, _tr.path());
		if (!temp_t) { return rt::FAIL_CREATE_TEXT; }
		
		//set TextRes text
		_tr.text(temp_t);

		//add to list
		if (TextRes_.size() == TextRes_.capacity()) 
			TextRes_.reserve(TextRes_.size()* TextRes_.size());
		
		TextRes_.push_back(&_tr);
		log("TextResManager::TextRes_.size() = " << TextRes_.size());
	}
	else
		return rt::ALREADY_IN_LIST;

	return rt::SUCCESS;
}

ss::rt ss::TextResManager::reset()
{
	log("TextResManager::reset()");
	rt ret = del_all_t();
	if (ret != rt::SUCCESS) return ret;

	TextRes_.clear();

	return load_nf();
}

ss::rt ss::TextResManager::del_t_p(char const* _path)
{
	log("TextResManager::del_t_p("<<_path<<")");
	int8_t i = find_tr_p(_path);
	if (i == rerr8) return rt::NOT_IN_LIST;
	return destroy_text(TextRes_[i]->text());
}

ss::rt ss::TextResManager::del_t_n(char const* _name)
{
	log("TextResManager::del_t_n("<<_name<<")");
	int8_t i = find_tr_n(_name);
	if (i == rerr8) return rt::NOT_IN_LIST;
	return destroy_text(TextRes_[i]->text());
}

ss::rt ss::TextResManager::del_t(TextRes* _tr)
{
	log("TextResManager::del_t("<<&_tr<<")");
	//int8_t i = find_tr(_tr);
	//if (i == rerr8) return rt::NOT_IN_LIST;
	//return destroy_text(TextRes_[i].text());
	return destroy_text(_tr->text());
}

ss::rt ss::TextResManager::del_t(size_t _index)
{
	log("TextResManager::del_t("<<_index<<")");
	if (_index<0 || _index>TextRes_.size()) return rt::OUT_OF_BOUNDS;
	return destroy_text(TextRes_[_index]->text());
}

ss::rt ss::TextResManager::del_all_t()
{
	log("TextResManager::del_all()");
	rt ret = rt::INITIAL;
	rt temp_rt = rt::SUCCESS;

	for (size_t i=0; i<TextRes_.size(); ++i)
	{
		ret = del_t(i);
		if (ret != rt::SUCCESS) temp_rt = ret;
		TextRes_[i]->text(nullptr);
	}
	return temp_rt;
}

int8_t ss::TextResManager::find_tr_p(char const* _path) const
{
	log("TextResManager::find_tr_p("<<_path<<")");
	for (size_t i = 0; i < TextRes_.size(); ++i)
		if (_path == TextRes_[i]->path())
			return static_cast<int8_t>(i);
	return rerr8;
}

int8_t ss::TextResManager::find_tr_n(char const* _name) const
{
	log("TextResManager::find_tr_n("<<_name<<")");
	for (size_t i = 0; i < TextRes_.size(); ++i)
		if (_name == TextRes_[i]->name())
			return static_cast<int8_t>(i);
	return rerr8;
}

int8_t ss::TextResManager::find_tr(TextRes* _tr) const
{
	log("TextResManager::find_tr("<<_tr<<")");
	for (size_t i = 0; i < TextRes_.size(); ++i)
		if (_tr == TextRes_[i])
			return static_cast<int8_t>(i);
	return rerr8;
}

ss::TextRes* ss::TextResManager::get_tr_p(char const* _path)
{
	log("TextResManager::get_tr_p("<<_path<<")");
	for (size_t i = 0; i < TextRes_.size(); ++i)
		if (_path == TextRes_[i]->path())
			return TextRes_[i];
	return &NF_;
}

ss::TextRes* ss::TextResManager::get_tr_n(char const* _name)
{
	log("TextResManager::get_tr_n("<<_name<<")");
	for (size_t i = 0; i < TextRes_.size(); ++i)
		if (_name == TextRes_[i]->name())
			return TextRes_[i];
	return &NF_;
}

ss::TextRes* ss::TextResManager::get_tr(size_t _index)
{
	log("TextResManager::get_tr("<<_index<<")");
	if (_index<0 || _index>TextRes_.size())
		return &NF_;
	else
		return TextRes_[_index];
}

ss::rt ss::TextResManager::load_nf()
{
	log("TextResManager::load_nf()");
	if (NF_.text()) return rt::SUCCESS;
	
	SDL_Texture* temp_t = create_text_from_path(Rend_, NFP_);
	if (!temp_t) return rt::FAIL_CREATE_TEXT;

	NF_.text(temp_t);
	//TextRes_.push_back(NF_);

	return rt::SUCCESS;
}

ss::rt ss::TextResManager::init()
{
	log("TextResManager::init()");
	//MAX_TEXT_RES = 10;
	TextRes_.reserve(20);

	NF_.name(NFN_);
	NF_.path(NFP_);

	Rend_ = nullptr;

	return rt::SUCCESS;// reset(Rend_);
}

ss::rt ss::TextResManager::destroy()
{
	log("TextResManager::destroy()");
	return del_all_t();
}
