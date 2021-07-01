#pragma once

#include <vector>

#include "ALL.h"
#include "TextRes.h"

/*--------------------------------------------------*/
namespace ss
/*--------------------------------------------------*/
{
	/*--------------------------------------------------*/
	typedef struct TRL_BASE
	/*--------------------------------------------------*/
	{
		/*--------------------------------------------------*/
		/*-------------Constructor/Desctructor--------------*/
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		TRL_BASE()
		/*--------------------------------------------------*/
		{
			log("TRL_base()");
			TRvec.reserve(10);
			NotFound_.name("not-found");
			NotFound_.path("not-found.png");
			Rend_ = nullptr;
		}

		///*--------------------------------------------------*/
		//TRL_BASE(SDL_Renderer* _rend)
		///*--------------------------------------------------*/
		//{
		//	log("TRL_BASE_CLASS("<<_rend<<")");
		//	TRvec.reserve(10);
		//	Rend_ = _rend;
		//	NotFound_.name("not-found");
		//	NotFound_.path("not-found.png");
		//	NotFound_.load_text(Rend_);
		//}

		/*--------------------------------------------------*/
		~TRL_BASE() 
		/*--------------------------------------------------*/
			{ log("~TRL_base()"); }
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*-------------Member Functions---------------------*/
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		rt load_all_text()
		/*--------------------------------------------------*/
		{
			log("TRL::load_all_text()");

			rt ret = rt::INITIAL;
			for (TextRes* _tr : TRvec)
			{
				ret = _tr->load_text(Rend_);
				if (ret != rt::OK) return ret;
			}
			return rt::OK;
		}
		/*--------------------------------------------------*/
		rt delete_all_text()
		/*--------------------------------------------------*/
		{
			log("TRL::delete_all_text()");

			rt ret = rt::INITIAL;

			std::vector<TextRes*>::iterator itr;

			for (itr=TRvec.begin(); itr!=TRvec.end(); ++itr)
			{
				ret = (*itr)->delete_text();
				if (ret != rt::OK) return ret;
			}

			return rt::OK;
		}
		/*--------------------------------------------------*/
		rt delete_list()
		/*--------------------------------------------------*/
		{
			log("TRL::delete_list()");
			rt ret = rt::INITIAL;

			ret = delete_all_text();
			if (ret != rt::OK) return ret;
			
			TRvec.clear();
			return rt::OK;
		}
		/*--------------------------------------------------*/
		size_t find_text(char const* _name)
		/*--------------------------------------------------*/
		{
			//log("TRL::find_text("<<_name<<")");

			for (size_t i = 0; i < TRvec.size(); ++i)
				if (TRvec[i]->name() == _name)
					return i;
			return rerr_sizet;
		}
		/*--------------------------------------------------*/
		SDL_Texture* get_text(size_t _index)
		/*--------------------------------------------------*/
		{
			//log("TRL::get_text("<<_index<<")");

			if (_index < 0 || _index >= TRvec.size()) return NotFound_.text();
			return TRvec[_index]->text();
		}
		/*--------------------------------------------------*/
		SDL_Texture* get_text(char const* _name)
		/*--------------------------------------------------*/
		{
			//log("TRL::get_text("<<_name<<")");
			return get_text(find_text(_name)); 
		}
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*------------Struct Member Elements----------------*/
		/*--------------------------------------------------*/
		std::vector<TextRes*>	TRvec;
		TextRes					NotFound_;
		SDL_Renderer*			Rend_;
		/*--------------------------------------------------*/

	/*--------------------------------------------------*/
	} TRL; // END	struct TRL_BASE_CLASS
	/*--------------------------------------------------*/
} // END	namespace ss

