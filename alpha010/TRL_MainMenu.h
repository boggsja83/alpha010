#pragma once

#include "Logger.h"
#include "TextRes.h"

namespace ss
{
	struct TRL_MainMenu
	{
		TextRes	menu_bg;
		TextRes test_tr;
		TextRes test2;

		TRL_MainMenu()
		{
			log("TRL_MainMenu()");

			menu_bg.name("menu-main");
			menu_bg.path("menu-main.png");

			test_tr.name("test");
			test_tr.path("test.png");

			test2.name("test_2");
			test2.path("test_256.png");
		}
		~TRL_MainMenu()
		{
			log("~TRL_MainMenu()");
		}
	};
	
} // END	namespace ss
