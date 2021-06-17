#include "VA_eng_menu.h"

uint8_t ss::va_eng_menu::init()
{
	asset_name = "eng-menu";
	asset_path = "eng-menu.png";

	z_ord = 0;

	// load asset into asset manager?  *try to do this
	// in state st_eng_menu or engine if possible

	return 0x00;
}

uint8_t ss::va_eng_menu::destroy()
{
	return 0x00;
}
