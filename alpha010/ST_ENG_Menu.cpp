#include "st_eng_menu.h"

uint8_t ss::st_eng_menu::enter() const
{
	log("st_eng_menu::enter()");
	return uint8_t();
}

uint8_t ss::st_eng_menu::pause() const
{
	log("st_eng_menu::pause()");
	return uint8_t();
}

uint8_t ss::st_eng_menu::resume() const
{
	log("st_eng_menu::resume()");
	return uint8_t();
}

uint8_t ss::st_eng_menu::exit() const
{
	log("st_eng_menu::exit()");
	return uint8_t();
}

uint8_t ss::st_eng_menu::input() const
{
	log("st_eng_menu::input()");
	return uint8_t();
}

uint8_t ss::st_eng_menu::draw() const
{
	log("st_eng_menu::draw()");
	return uint8_t();
}

uint8_t ss::st_eng_menu::init()
{
	log("st_eng_menu::init()");
	asset_name = "eng-menu";
	return uint8_t();
}

uint8_t ss::st_eng_menu::destroy()
{
	log("st_eng_menu::destroy()");
	return uint8_t();
}
