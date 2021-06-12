#include "Engine.h"

uint8_t ss::engine::init()
{
    //int test[] = {1,54,86,92,42,21,70,14,11,23,65,98,015,11,525,2,45,53,6,7,8,};
    //int n = sizeof(test) / sizeof(test[0]);

    uint8_t ret = 0xFF;
    ret = init_locals();


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

    return ret;
}

uint8_t ss::engine::init_locals()
{
    On_ = false;

    return uint8_t();
}

uint8_t ss::engine::destroy()
{
    return uint8_t();
}

uint8_t ss::engine::loop()
{
    return uint8_t();
}

uint8_t ss::engine::input()
{
    //poll events
    //broadcast to appropriate entities
    return uint8_t();
}

uint8_t ss::engine::draw()
{
    // draw all assets?
    return uint8_t();
}
