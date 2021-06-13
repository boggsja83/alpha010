#pragma once
#include "SDP.h"

namespace ss
{
    class st_eng_menu :
        public state
    {
    private:
    public:
        // BEGIN    state inherits
        virtual uint8_t enter() const override;
        virtual uint8_t pause() const override;
        virtual uint8_t resume() const override;
        virtual uint8_t exit() const override;

        virtual uint8_t input() const override;
        virtual uint8_t draw() const override;
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
        
        char const* asset_name;

    }; // END  class st_eng_menu
} // END    namespace
