#pragma once

#include "Logger.h"
#include "SDP.h"

namespace ss
{
    class st_eng_menu :
        public state
    {
    private:
    public:
        // BEGIN    state inherits
        virtual uint8_t enter()  override;
        virtual uint8_t pause()  override;
        virtual uint8_t resume()  override;
        virtual uint8_t exit()  override;

        virtual uint8_t input()  override;
        virtual uint8_t draw()  override;
        // END      state inherits

        st_eng_menu()
        {
            log("st_eng_menu()");
            uint8_t r = init();
        }
        ~st_eng_menu()
        {
            log("~st_eng_menu()");
            uint8_t r = destroy();
        }

        uint8_t init();
        uint8_t destroy();
        
        //this will be asset instead
        //char const* asset_name;

    }; // END  class st_eng_menu
} // END    namespace
