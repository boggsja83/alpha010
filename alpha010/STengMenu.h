#pragma once

#include "ALL.h"
#include "SDP.h"

namespace ss
{
    class st_eng_menu :
        public state
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

        st_eng_menu()
        {
            log("st_eng_menu()");
            rt ret = init();
        }
        ~st_eng_menu()
        {
            log("~st_eng_menu()");
            rt ret = destroy();
        }

        rt init();
        rt destroy();

    }; // END  class st_eng_menu
} // END    namespace
