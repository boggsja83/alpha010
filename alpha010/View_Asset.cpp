#include "view_asset.h"

uint8_t ss::view_asset::init()
{
    log("view_asset::init()");
    
    z_ord = 0xFF;

    return 0x00;
}

uint8_t ss::view_asset::destroy()
{
    log("view_asset::destroy()");
    return 0x00;
}

//uint8_t ss::view_asset::draw()
//{
//    
//    return uint8_t();
//}
