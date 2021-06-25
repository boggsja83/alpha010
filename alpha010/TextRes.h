#pragma once

#include "ALL.h"

#include "SDL.h"

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
			log("~TextRes()");
			rt ret = destroy();
		}

		inline char const* name() const { return Name_; }
		inline char const* path() const { return Path_; }
		inline SDL_Texture* text() const { return Texture_; }

		inline void name(char const* _n) { Name_ = const_cast<char*>(_n); }
		inline void path(char const* _p) { Path_ = const_cast<char*>(_p); }
		//inline void text(SDL_Texture const * _t) { Texture_ = const_cast<SDL_Texture*>(_t); }
		inline void text(SDL_Texture* _t) { Texture_ = _t; }

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
		// actual resource is deleted by a controller
		// Texture_ just remains a pointer for reference, 
		// not responsible for tracking [resides in textresmanager
		return rt::SUCCESS;
	}
} // END	namespace ss
