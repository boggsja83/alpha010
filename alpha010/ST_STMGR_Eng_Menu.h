#pragma once

#include "Logger.h"
#include "ST_ENG_Menu.h"

namespace ss
{
	class st_stmgr_eng_menu :
		public state
	{
	public:
		// BEGIN	state inherits
		virtual uint8_t enter()	 const;
		virtual uint8_t pause()	 const;
		virtual uint8_t resume() const;
		virtual uint8_t exit()	 const;

		virtual uint8_t draw()	 const;
		virtual uint8_t input()	 const;
		// END		state inherits


		st_stmgr_eng_menu()
		{
			log("st_stmgr_eng_menu()");
			uint8_t r = init();
		}
		~st_stmgr_eng_menu()
		{
			log("~st_stmgr_eng_menu()");
			uint8_t r = destroy();
		}

		uint8_t init();
		uint8_t destroy();

		st_eng_menu eng_menu_;

	}; // END	class st_stmgr_eng_menu
} // END	namespace ss