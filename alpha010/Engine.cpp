#include "Engine.h"

ss::rt ss::Engine::init()
{
    log("Engine::init()");
    
    rt ret = rt::INITIAL;

    ret = init_locals();
    if (ret != rt::OK) { return ret; }

    ret = push_state(&ST_em_);
    if (ret != rt::OK) { return ret; }
    
    return ret;
}

ss::rt ss::Engine::init_locals()
{
    log("Engine::init_locals()");
    
    rt ret = rt::INITIAL;

    On_ = false;
    
    return rt::OK;
}

ss::rt ss::Engine::destroy()
{
    log("Engine::destroy()");
    return rt::OK;
}

ss::rt ss::Engine::loop()
{
    rt ret = rt::INITIAL;

    log("Engine::loop()");
    
    bool one_frame = true;
    bool user_quit = false;

    On_ = true;
    while (On_ && !user_quit)
    {
        SDL_Delay(16);//fake 60fps

        one_frame = true;
        user_quit = false;
        while(one_frame && !user_quit)
        {
            ret = input_state();
            if (ret == rt::INPUT_RECEIVED)
                one_frame = false;
            else if (ret == rt::QUIT)
                user_quit = true;
        }
        if (user_quit) return rt::QUIT;

        ret = draw_state();
        if (ret != rt::OK) return ret;
    }
    
    return ret;
}

