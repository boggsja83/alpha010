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
		TextResManager()
		{
			log("TextResManager()");
			rt ret = init();
		}
		~TextResManager() 
		{
			log("~TextResManager()");
			rt ret = destroy();
		}

		rt load_tr(SDL_Renderer*,TextRes&);

		//these prob shouldnt be const
		TextRes* get_tr(char const*) const;
		TextRes* get_tr(int8_t) const;
		//SDL_Texture* get_t(char const*) const;
		//SDL_Texture* get_t(ITextRes*) const;//essentially makes sure the text is loaded...
		
		rt del_tr_p(char const*);
		rt del_tr_n(char const*);
		rt del_tr(TextRes*);
		rt del_tr(int8_t);

		int8_t find_tr_p(char const*) const;
		int8_t find_tr_n(char const*) const;
		int8_t find_tr(TextRes *) const;

		TextRes* get_tr_p(char const*) const;
		TextRes* get_tr_n(char const*) const;
		TextRes* get_tr(size_t) const;

		int const MAX_TEXT_RES = 10;

	private:
		rt init();
		rt destroy();

		std::vector<TextRes> TextRes_;

		//std::vector<TextRes> TextRes_;
	}; // END	class TextResManager

} // END	namespace ss