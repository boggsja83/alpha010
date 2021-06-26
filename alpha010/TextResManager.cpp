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

		//resize vec if needed
		if (TRvec.size() >= TRvec.capacity())
		{
			TRvec.reserve(TRvec.size() * TRvec.size());
			log("TextResManager()::push_tr() reserve: TRvec.capacity() = " << TRvec.capacity());
		}

		//add to list
		TRvec.push_back(&_tr);
		log("TextResManager::TextRes_.size() = " << TRvec.size());
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

	TRvec.clear();

	return load_nf();
}

void ss::TextResManager::set_rend(SDL_Renderer* _rend)
{
	log("TextResManager::set_rend(" << _rend << ")");
	isRendSet = true;
	Rend_ = _rend;
	return;
}

ss::rt ss::TextResManager::del_t_p(char const* _path)
{
	log("TextResManager::del_t_p("<<_path<<")");
	int8_t i = find_tr_p(_path);
	if (i == rerr8) return rt::NOT_IN_LIST;

	rt ret = destroy_text(TRvec[i]->text());
	if (ret!=rt::SUCCESS) return rt::FAIL_DESTROY_TEXT;
	TRvec[i]->text(nullptr);

	return rt::SUCCESS;
	//return destroy_text( (TRvec[i]->text()) );
}

ss::rt ss::TextResManager::del_t_n(char const* _name)
{
	log("TextResManager::del_t_n("<<_name<<")");
	int8_t i = find_tr_n(_name);
	if (i == rerr8) return rt::NOT_IN_LIST;
	//return destroy_text(TRvec[i]->text());
	rt ret = destroy_text(TRvec[i]->text());
	if (ret!=rt::SUCCESS) return rt::FAIL_DESTROY_TEXT;
	TRvec[i]->text(nullptr);
	
	return rt::SUCCESS;
}

ss::rt ss::TextResManager::del_t(TextRes* _tr)
{
	log("TextResManager::del_t("<<&_tr<<")");
	//int8_t i = find_tr(_tr);
	//if (i == rerr8) return rt::NOT_IN_LIST;
	//return destroy_text(TextRes_[i].text());
	//rt ret = destroy_text(_tr->text());
	//if (ret != rt::SUCCESS) return ret;

	//_tr->text(nullptr);

	rt ret = destroy_text(_tr->text());
	if (ret!=rt::SUCCESS) return rt::FAIL_DESTROY_TEXT;
	_tr->text(nullptr);

	return rt::SUCCESS;
	//return destroy_text(_tr->text());;
}

ss::rt ss::TextResManager::del_t(size_t _index)
{
	log("TextResManager::del_t("<<_index<<")");
	if (_index<0 || _index>TRvec.size()) return rt::OUT_OF_BOUNDS;
	//return destroy_text(TRvec[_index]->text());
	
	rt ret = destroy_text(TRvec[_index]->text());
	if (ret!=rt::SUCCESS) return rt::FAIL_DESTROY_TEXT;

	TRvec[_index]->text(nullptr);

	log(TRvec[_index]);

	return rt::SUCCESS;
}

// deletes all the SDL_Texture*s in vec AND
// also deletes SDL_Texture in NotFound_
// NOTE: ONLY DELETES THE TEXTURE MEMEBER
ss::rt ss::TextResManager::del_all_t()
{
	log("TextResManager::del_all_t()");
	rt ret = rt::INITIAL;
	rt temp_rt = rt::SUCCESS;

	//SDL_Texture* temp_t = nullptr;

	ret = destroy_text(NotFound_.text());
	if (ret!=rt::SUCCESS)
		log("TextResManager::reset() destroy_text() WARNING: " << NotFound_.text());
	else
	if (ret != rt::SUCCESS) return ret;

	NotFound_.text(nullptr);

	for (size_t i=0; i<TRvec.size(); ++i)
	{
		ret = del_t(i);
		if (ret != rt::SUCCESS) temp_rt = ret;
		//TRvec[i]->text(nullptr);
	}
	return temp_rt;
}

int8_t ss::TextResManager::find_tr_p(char const* _path) const
{
	log("TextResManager::find_tr_p("<<_path<<")");
	for (size_t i = 0; i < TRvec.size(); ++i)
		if (_path == TRvec[i]->path())
			return static_cast<int8_t>(i);
	return rerr8;
}

int8_t ss::TextResManager::find_tr_n(char const* _name) const
{
	log("TextResManager::find_tr_n("<<_name<<")");
	for (size_t i = 0; i < TRvec.size(); ++i)
		if (_name == TRvec[i]->name())
			return static_cast<int8_t>(i);
	return rerr8;
}

int8_t ss::TextResManager::find_tr(TextRes* _tr) const
{
	log("TextResManager::find_tr("<<_tr<<")");
	for (size_t i = 0; i < TRvec.size(); ++i)
		if (_tr == TRvec[i])
			return static_cast<int8_t>(i);
	return rerr8;
}

ss::TextRes* ss::TextResManager::get_tr_p(char const* _path)
{
	log("TextResManager::get_tr_p("<<_path<<")");
	for (size_t i = 0; i < TRvec.size(); ++i)
		if (_path == TRvec[i]->path())
			return TRvec[i];
	return &NotFound_;
}

ss::TextRes* ss::TextResManager::get_tr_n(char const* _name)
{
	log("TextResManager::get_tr_n("<<_name<<")");
	for (size_t i = 0; i < TRvec.size(); ++i)
		if (_name == TRvec[i]->name())
			return TRvec[i];
	return &NotFound_;
}

ss::TextRes* ss::TextResManager::get_tr(size_t _index)
{
	log("TextResManager::get_tr("<<_index<<")");
	if (_index<0 || _index>TRvec.size())
		return &NotFound_;
	else
		return TRvec[_index];
}

ss::rt ss::TextResManager::load_nf()
{
	log("TextResManager::load_nf()");
	if (NotFound_.text()) return rt::NF_ALREADY_EXISTS;
	
	SDL_Texture* temp_t = create_text_from_path(Rend_, NotFound_path);
	if (!temp_t) return rt::FAIL_CREATE_TEXT;

	NotFound_.text(temp_t);
	//TextRes_.push_back(NF_);

	return rt::SUCCESS;
}

ss::rt ss::TextResManager::init()
{
	log("TextResManager::init()");
	
	//PUT THIS BACK IN JUST TESTING
	//RESIZING IN PUSH_TR()!!!!!
	TRvec.reserve(5);

	NotFound_.name(NotFound_name);
	NotFound_.path(NotFound_path);

	Rend_ = nullptr;
	isRendSet = false;

	return rt::SUCCESS;// reset(Rend_);
}

ss::rt ss::TextResManager::destroy()
{
	log("TextResManager::destroy()");
	return del_all_t();
}
