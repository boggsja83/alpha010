#pragma once

#include "ALL.h"

#include "TRL.h"

//#include "TextRes.h"
//#include <vector>

namespace ss
{
	typedef struct TRL_eng_menu : TRL_BASE
	{
		/*--------------------------------------------------*/
		/*-----------------TRL_BASE Functions---------------*/
		/*--------------------------------------------------*/
		//rt			load_all_text()
		//rt			delete_all_text()
		//size_t		find_text(char const* _name)
		//SDL_Texture*	get_text(size_t _index)
		//SDL_Texture*	get_text(char const* _name)
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*-----------------TRL_BASE Elements----------------*/
		/*--------------------------------------------------*/
		//std::vector<TextRes*>		TRvec;
		//TextRes					NotFound_;
		//SDL_Renderer*				Rend_;
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*--------------Constructor/Destructor--------------*/
		/*--------------------------------------------------*/
		
		/*--------------------------------------------------*/
		TRL_eng_menu() = delete;
		TRL_eng_menu(TRL_eng_menu&) = delete;
		void* operator=(TRL_eng_menu const&) = delete;
		/*--------------------------------------------------*/
	
		/*--------------------------------------------------*/
		TRL_eng_menu(SDL_Renderer* _rend) 
		/*--------------------------------------------------*/
		{
			log("TRL_eng_menu_("<<_rend<<")");

			menu_main.name("menu-main");
			menu_main.path("menu-main.png");
			TRvec.push_back(&menu_main);

			test_tr.name("test");
			test_tr.path("test.png");
			TRvec.push_back(&test_tr);

			test2.name("test_2");
			test2.path("test_2.png");
			TRvec.push_back(&test2);

			red.name("red");
			red.path("red.jpg");
			TRvec.push_back(&red);

			Rend_=_rend;
			NotFound_.load_text(Rend_);
		}
		/*--------------------------------------------------*/
		~TRL_eng_menu()
		/*--------------------------------------------------*/
			{ log("~TRL_eng_menu()"); }
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*--------------Struct Member ELements--------------*/
		/*--------------------------------------------------*/
		TextRes menu_main;
		TextRes test_tr;
		TextRes test2;
		TextRes red;
		/*--------------------------------------------------*/

	/*--------------------------------------------------*/
	} TRLengMenu; // END	struct TRL_ENG_MENU
	/*--------------------------------------------------*/
} // END	namespace ss

