#pragma once

#include <vector>

#include "ALL.h"
#include "SDP.h"

#include "TextRes.h"
#include "TRL_MainMenu.h"

namespace ss
{
    class ST_eng_menu :
        public State
    {
    private:
    public:
        // BEGIN    state inherits
        virtual rt enter()  override;
        virtual rt pause()  override;
        virtual rt resume()  override;
        virtual rt exit()  override;

        virtual rt input()  override;
        virtual rt draw()  override;
        // END      state inherits

        ST_eng_menu()
        {
            log("ST_eng_menu()");
            rt ret = init();
        }
        ~ST_eng_menu()
        {
            log("~ST_eng_menu()");
            rt ret = destroy();
        }

        rt init();
        rt destroy();

        TRL_MainMenu trl_main;
        //std::vector<TextRes> TRvec;

        char const* text_name = "menu-main";
    }; // END  class ST_eng_menu
} // END    namespace ss
