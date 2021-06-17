#pragma once

#include "Logger.h"
#include "View_Asset.h"

namespace ss
{
    class va_eng_menu :
        public view_asset
    {
        // BEGIN    view_asset inherits
        
        //uint8_t			init();//overloaded not really
        //uint8_t			destroy();//overloaded not really
        ////uint8_t			draw();//not sure yet but yes most likely

        //char const* asset_name;
        //char const* asset_path;
        //SDL_Rect		src_rect;
        //SDL_Rect		dst_rect;

        //uint8_t			z_order;
        
        // END      view_asset inherits
        public:
        va_eng_menu()
        {
            log("va_eng_menu()");
            uint8_t ret = init();
        }
        ~va_eng_menu()
        {
            log("~va_eng_menu()");
            uint8_t ret = destroy();
        }

        uint8_t init();
        uint8_t destroy();

    }; // END  class va_eng_menu
} // END    namespace ss
