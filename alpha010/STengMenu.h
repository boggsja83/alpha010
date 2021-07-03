#pragma once

#include <vector>

#include "ALL.h"
#include "SDP.h"

//#include "SDLwrapper.h"
#include "TRLengMenu.h"
#include "ICDengMenu.h"
#include "InputController.h"
#include "ViewController.h"

/*--------------------------------------------------*/
namespace ss
/*--------------------------------------------------*/
{
    /*--------------------------------------------------*/
    class ST_eng_menu : 
    /*--------------------------------------------------*/
        public State
    /*--------------------------------------------------*/
    {
        /*--------------------------------------------------*/
        /*---------------------State Functions--------------*/
        /*--------------------------------------------------*/
    public:
        virtual rt enter()  override;
        virtual rt pause()  override;
        virtual rt resume() override;
        virtual rt exit()   override;

        virtual rt input()  override;
        virtual rt draw()   override;

        /*--------------------------------------------------*/
        /*---------------Constructors/Destructor------------*/
        /*--------------------------------------------------*/
    public:
        /*--------------------------------------------------*/
        ST_eng_menu() = delete;
        ST_eng_menu(ST_eng_menu&) = delete;
        void* operator=(ST_eng_menu const&) = delete;
        /*--------------------------------------------------*/
        ST_eng_menu(ViewController* _view, InputController* _input): TRL_(_view->rend())
        /*--------------------------------------------------*/
        {
            log("ST_eng_menu("<<_view<<". " << _input << ")");
            rt ret = init();
            this->View_ = _view;
            this->Input_ = _input;
        }
        /*--------------------------------------------------*/
        ~ST_eng_menu()
        /*--------------------------------------------------*/
        {
            log("~ST_eng_menu()");
            rt ret = destroy();
        }
        /*--------------------------------------------------*/

        /*--------------------------------------------------*/
        /*------------------Init/Delete---------------------*/
        /*--------------------------------------------------*/
    private:
        /*--------------------------------------------------*/
        rt init();
        rt destroy();
        /*--------------------------------------------------*/

        /*--------------------------------------------------*/
        /*-----------------Member Variables-----------------*/
        /*--------------------------------------------------*/
    //public:
    private:
        char const*         Name_tex_ = "red";
    //private:
        // controllers (make a passthrough object...)
        ViewController*     View_;
        InputController*    Input_;
        
        // texture resource list
        TRLengMenu          TRL_;
        
        // input context
        //ICDengMenu          ICD_;
        InputContext        IC_;
        ArrIC               ICA_;
        /*--------------------------------------------------*/

        /*--------------------------------------------------*/
        /*-----------------Getter Functions-----------------*/
        /*--------------------------------------------------*/
    public:
        /*--------------------------------------------------*/
        inline char const*      text_name() const
        /*--------------------------------------------------*/
                                    { return Name_tex_; }
        /*--------------------------------------------------*/
        inline SDL_Renderer*    rend() const
        /*--------------------------------------------------*/
                                    { return View_->rend(); }
        /*--------------------------------------------------*/
        inline TRL&             trl()
        /*--------------------------------------------------*/
                                    { return TRL_; }
        /*--------------------------------------------------*/

    }; // END  class ST_eng_menu

} // END    namespace ss
