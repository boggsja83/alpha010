#pragma once

#include "ALL.h"

#include "TRL.h"

//#include "TextRes.h"
//#include <vector>

namespace ss
{
	typedef struct TRL_ENG_MENU_ : TRL_BASE
	{
		/*--------------------------------------------------*/
		/*-----------------TRL_BASE Elements----------------*/
		/*--------------------------------------------------*/
		//rt	load_all_text(SDL_Renderer*)
		//rt	delete_all_text();
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*-----------------TRL_BASE Functions---------------*/
		/*--------------------------------------------------*/
		//std::vector<TextRes*>		TRvec;
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*--------------Constructor/Destructor--------------*/
		/*--------------------------------------------------*/
		
		/*--------------------------------------------------*/
		TRL_ENG_MENU_()
		/*--------------------------------------------------*/
		{
			log("TRL_ENG_MENU_()");

			menu_main.name("menu-main");
			menu_main.path("menu-main.png");
			TRvec.push_back(&menu_main);

			test_tr.name("test");
			test_tr.path("test.png");
			TRvec.push_back(&test_tr);

			test2.name("test_2");
			test2.path("test_2.png");
			TRvec.push_back(&test2);
		}
		/*--------------------------------------------------*/
		~TRL_ENG_MENU_()
		/*--------------------------------------------------*/
			{ log("~TRL_ENG_MENU_()"); }
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*--------------Struct Member ELements--------------*/
		/*--------------------------------------------------*/
		TextRes menu_main;
		TextRes test_tr;
		TextRes test2;
		/*--------------------------------------------------*/

	/*--------------------------------------------------*/
	} TRL_em; // END	struct TRL_ENG_MENU
	/*--------------------------------------------------*/
} // END	namespace ss

