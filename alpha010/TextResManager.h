#pragma once

#include <vector>

#include "ALL.h"
#include "SDLwrapper.h"
#include "TextRes.h"

namespace ss
{
	class TextResManager
	{
	public:
		//TextResManager() = delete;
		TextResManager()
		{
			log("TextResManager()");
			rt ret = init();
			log("TextResManager::init() ret: " << c2m(ret));
		}
		~TextResManager() 
		{
			log("~TextResManager()");
			rt ret = destroy();
			log("TextResManager::destroy() ret: " << c2m(ret));
		}

		inline TextRes* get_nf() { return &NotFound_; }

		rt load_nf();
		rt push_tr(TextRes&);
		rt reset();

		void set_rend(SDL_Renderer* const _rend);
		

		//need remove funcc tions for removing from list
		rt del_t_p(char const*);
		rt del_t_n(char const*);
		rt del_t(TextRes*);
		rt del_t(size_t);
		rt del_all_t();

		int8_t find_tr_p(char const*) const;
		int8_t find_tr_n(char const*) const;
		int8_t find_tr(TextRes *) const;

		TextRes* get_tr_p(char const*);
		TextRes* get_tr_n(char const*);
		TextRes* get_tr(size_t);


		//below not really needed at all...
		//size_t const MAX_TEXT_RES = 10;//use this when need to resize
		//TextRes NF_;//not found TextRes
	private:
		rt init();
		rt destroy();

		std::vector<TextRes*> TRvec;

		SDL_Renderer* Rend_;//NEED TO SET THIS EXTERNALLY[try constructor first...]
		bool isRendSet;

		TextRes NotFound_;
		char const* NotFound_name = "not-found";
		char const* NotFound_path = "not-found.png";
		
	}; // END	class TextResManager

} // END	namespace ss
