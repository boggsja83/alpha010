#include "Engine.h"

ss::rt ss::engine::init()
{
    log("engine::init()");

    rt ret = rt::INITIAL;

    ret = init_locals();
    if (ret != rt::SUCCESS) { return ret; }

    ret = push_state(&st_em);
    if (ret != rt::SUCCESS) { return ret; }

    //On_ = true;
    //ret = loop();
 
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



ss::rt ss::engine::init_locals()
{
    log("engine::init_locals()");
    
    rt ret = rt::INITIAL;

    On_ = false;
    
    TRM_.set_rend(View_.get_r());
    ret = TRM_.reset();//sets TRM_::NF_ (not found TextRes)
    //if (ret != rt::SUCCESS) return ret;

    return ret;// rt::SUCCESS;
}

ss::rt ss::engine::destroy()
{
    log("engine::destroy()");
    return rt::SUCCESS;
}

ss::rt ss::engine::loop()
{
    rt ret = rt::INITIAL;

    log("engine::loop()");
    
    On_ = true;

    while (On_)
    {
        ret = input();
        if (ret != rt::SUCCESS) return ret;
        
        ret = draw();
        if (ret != rt::SUCCESS) return ret;

        On_ = false;
    }

    return ret;
}

ss::rt ss::engine::input()
{
    log("engine::input()");
    //poll events
    //broadcast to appropriate entities
    //prob not broadcast.  just state::update 
    //called by state_holder::update()

    
    return input_state();
}

ss::rt ss::engine::draw()
{
    log("engine::draw()");
   
    rt ret = rt::INITIAL;
    ret = rend_cpy(View_.get_r(),TRM_.get_nf()->text(),NULL,NULL);
    if (ret != rt::SUCCESS)return ret;
    
    SDL_RenderPresent(View_.get_r());

    return draw_state();
}
