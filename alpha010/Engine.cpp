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
    
    bool oneFrame = true;
    bool user_quit = false;

    On_ = true;
    while (On_ && !user_quit)
    {
        oneFrame = true;
        user_quit = false;
        while(oneFrame && !user_quit)
        {
            ret = input_state();
            if (ret == rt::INPUT_RECEIVED)
                oneFrame = false;
            else if (ret == rt::QUIT)
                user_quit = true;
        }
        if (user_quit) return rt::QUIT;

        ret = draw_state();
        if (ret != rt::OK) return ret;
    }
    
    return ret;
}

