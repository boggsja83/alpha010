#include "State_Mgr.h"

uint8_t ss::state_mgr::init()
{
    log("state_mgr::init()");
    uint8_t r = push_state(&eng_menu);
    return r;
}

uint8_t ss::state_mgr::destroy()
{
    log("state_mgr::destroy()");
    return uint8_t();
}
