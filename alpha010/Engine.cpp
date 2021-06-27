#include "Engine.h"

ss::rt ss::Engine::init()
{
    log("Engine::init()");
    
    rt ret = rt::INITIAL;

    ret = init_locals();
    if (ret != rt::SUCCESS) { return ret; }

    //ST_em_.rend(View_.rend());
    ret = push_state(&ST_em_);
    if (ret != rt::SUCCESS) { return ret; }

    //// TRM testing stuff
    //// TRM_.set_rend(View_.get_r());
    //TRM_.set_rend(REND_);

    //ret = TRM_.load_nf();
    //if (ret != rt::SUCCESS) return ret;

    //ret = TRM_.push_tr(ST_em_.trl_main.menu_main);
    //if (ret!= rt::SUCCESS) return ret;
    //
    //ret = TRM_.push_tr(ST_em_.trl_main.test_tr);
    //if (ret != rt::SUCCESS) return ret;

    //ret = TRM_.push_tr(ST_em_.trl_main.test2);
    //if (ret != rt::SUCCESS) return ret;

    return ret;
}
    

    //int test[] = {1,54,86,92,42,21,70,14,11,23,65,98,015,11,525,2,45,53,6,7,8,};
    //int n = sizeof(test) / sizeof(test[0]);
    // 
    //SDL_Texture* ttt = nullptr;
    //std::array<std::pair<int, SDL_Texture*>,100> arr;
    //
    //int r = seed_(NULL);

    //for (size_t j=0;j< arr.size();++j)
    //{
    //    ttt = sdl_inst.create_text(sdl_inst.Rend_, sdl_inst.pixel_format_rend, SDL_TEXTUREACCESS_TARGET, sdl_inst.width_win, sdl_inst.height_win);
    //    arr[j] = std::make_pair(rand_int(0,4), ttt);
    //}

    //r = quickSort(arr.data(), 0, arr.size()-1);

    //std::array<std::pair<int, SDL_Texture*>,100>::iterator itr;
    //for (itr=arr.begin(); itr!=arr.end(); ++itr)
    //{
    //    log("1: "<<itr->first<<" 2: "<<itr->second);
    //}


    //for (size_t j = 0; j < arr.size(); ++j)
    //{
    //    sdl_inst.destroy_text(arr[j].second);
    //}



    //r = quickSort(test, 0, n-1);



ss::rt ss::Engine::init_locals()
{
    log("Engine::init_locals()");
    
    rt ret = rt::INITIAL;

    On_ = false;
    
    //TRM_.set_rend(View_.get_r());
    //ret = TRM_.load_nf();//load NotFound_ TextRes
    //if (ret != rt::SUCCESS) return ret;

    //return ret;
    return rt::SUCCESS;
}

ss::rt ss::Engine::destroy()
{
    log("Engine::destroy()");
    return rt::SUCCESS;
}

ss::rt ss::Engine::loop()
{
    rt ret = rt::INITIAL;

    log("Engine::loop()");


    //// TRM testing stuff
    //TRM_.set_rend(View_.get_r());
    ////TRM_.set_rend(Rend_);

    //ret = TRM_.load_nf();
    //if (ret != rt::SUCCESS) return ret;

    //ret = TRM_.push_tr(ST_em_.trl_main.menu_main);
    //if (ret != rt::SUCCESS) return ret;

    //ret = TRM_.push_tr(ST_em_.trl_main.test_tr);
    //if (ret != rt::SUCCESS) return ret;

    //ret = TRM_.push_tr(ST_em_.trl_main.test2);
    //if (ret != rt::SUCCESS) return ret;


    
    On_ = true;

    while (On_)
    {
        bool oneFrame = true;
        while(oneFrame)
        {
            ret = input();
            if (ret == rt::INPUT_RECEIVED) oneFrame = false;
            else if (ret != rt::SUCCESS) return ret;
        }

        ret = draw();
        if (ret != rt::SUCCESS) return ret;

        //On_ = false;
    }

    return ret;
}

ss::rt ss::Engine::input()
{
    //log("Engine::input()");
    //poll events
    //broadcast to appropriate entities
    //prob not broadcast.  just state::update 
    //called by state_holder::update()

    SDL_Event ev;
    SDL_PollEvent(&ev);

    switch (ev.type)
    {
    case SDL_QUIT:
        On_ = false;
        return rt::INPUT_RECEIVED;
    case SDL_KEYDOWN:
        break;
    case SDL_KEYUP:
        if (ev.key.keysym.scancode == SDL_SCANCODE_Q) { On_ = false; return rt::INPUT_RECEIVED; }
        if (ev.key.keysym.scancode == SDL_SCANCODE_SPACE) return rt::INPUT_RECEIVED;
        break;
    default:
        break;
    }

    return input_state();
}

ss::rt ss::Engine::draw()
{
    log("Engine::draw()");
   
    //SDL_RenderClear(View_.rend());
    ////SDL_RenderClear(Rend_);

    //rt ret = rt::INITIAL;
    ////ret = rend_cpy(View_.get_r(),TRM_.get_nf()->text(),NULL,NULL);
    ////if (ret != rt::SUCCESS) return ret;
    //
    //ret = rend_cpy(View_.rend(), TRM_.get_tr_n("menu-main")->text(), NULL, NULL );
    ////ret = rend_cpy(Rend_, TRM_.get_tr_n("menu-main")->text(), NULL, NULL);

    //SDL_RenderPresent(View_.rend());
    ////SDL_RenderPresent(Rend_);

    return draw_state();
}
