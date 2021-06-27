#pragma once

#include "ALL.h"

#include "SDLwrapper.h"

namespace ss
{
	class TextRes
	{
	public:
		TextRes() 
		{
			log("TextRes()");
			rt ret = init();
		}
		~TextRes()
		{
			log("~TextRes(): " << this);
			rt ret = destroy();
		}

		inline char const* name() { return Name_; }
		inline char const* path() { return Path_; }
		inline SDL_Texture* text() { return Texture_; }

		inline void name(char const* _n) { Name_ = _n; }
		inline void path(char const* _p) { Path_ = _p; }
		inline void text(SDL_Texture * _t) { Texture_ = _t; }
		//inline void text(SDL_Texture* _t) { Texture_ = _t; }

		inline rt load_text(SDL_Renderer*);
		inline rt delete_text();

		inline bool operator==(TextRes const &_rhs)
		{
			//only care about paths being equal??
			//(we cant have same names either...)
			if (this->Name_ != _rhs.Name_) { return false; }
			if (this->Path_ != _rhs.Path_) { return false; }

			// does texture check need to be included here??
			//if (this->Texture_ != _rhs.Texture_) { return false; }

			return true;
		}

	private:
		inline rt init();
		inline rt destroy();

		char const*		Name_;
		char const*		Path_;
		SDL_Texture*	Texture_;
	}; // END	class ITextRes

	rt TextRes::init()
	{
		log("TextRes::init()");
		Texture_ = nullptr;
		return rt::SUCCESS;
	}

	rt TextRes::destroy()
	{
		log("TextRes::destroy()");
		return delete_text();
	}

	rt TextRes::load_text(SDL_Renderer* _rend)
	{
		Texture_ = create_text_from_path(_rend, Path_);
		if (Texture_) return rt::SUCCESS;
		else return rt::FAIL_CREATE_TEXT;
	}

	rt TextRes::delete_text()
	{
		rt ret = rt::INITIAL;

		if (Texture_)
		{
			ret = destroy_text(Texture_);
			if (ret != rt::SUCCESS) return ret;
		}
		Texture_ = nullptr;
		return rt::SUCCESS;
	}
} // END	namespace ss
