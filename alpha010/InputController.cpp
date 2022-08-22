#include "InputController.h"

/*--------------------------------------------------*/
ss::rt ss::InputController::init()
/*--------------------------------------------------*/
{
	log("InputController::init()");
	rt ret = rt::INITIAL;

	//ret = init_event_map();
	//if (ret != rt::OK) return ret;

	ret = init_locals();
	if (ret != rt::OK) return ret;

	ret = init_sdl_input();
	if (ret != rt::OK) return ret;

	return ret;
}
/*--------------------------------------------------*/
ss::rt ss::InputController::destroy()
/*--------------------------------------------------*/
{
	log("InputController::destroy()");
	rt ret = rt::INITIAL;

	ret = destroy_sdl_input();
	if (ret != rt::OK) return ret;

	return ret;
}
///*--------------------------------------------------*/
//SDL_Event ss::InputController::poll_event()
///*--------------------------------------------------*/
ss::rt ss::InputController::input(ArrICD& _icda, ArrIRT& _irta)
{
	SDL_Event	ev;
	size_t		temp_sc = SDL_SCANCODE_UNKNOWN;
	rt			ret = rt::OK;
	bool		ks_change =	false;

	while (SDL_PollEvent(&ev))
	{
		temp_sc = ev.key.keysym.scancode;
		ks_change = false;
		
		switch (ev.type)
		{
		case SDL_QUIT:
			return rt::QUIT;
		case SDL_KEYDOWN:
			SC_[temp_sc] = true;
			
			//TMR_[temp_sc].start();	// 7/1/22 - this should not be used
									// should be a timestamp...

			//_irta[temp_sc].TI_ = TMR_[temp_sc];
			//_irta[temp_sc].TI_.TPstart_ = TMR_[temp_sc].TPstart_;
			//_irta[temp_sc].TI_.On_ = true;
			
			ks_change = true;
			break;
		case SDL_KEYUP:
			SC_[temp_sc] = false;
			//TMR_[temp_sc].stop(); // 7/1/22 - this should not be used
								  // should be a timestamp...

			//_irta[temp_sc].TI_ = TMR_[temp_sc];
			//_irta[temp_sc].TI_.TPstop_ = TMR_[temp_sc].TPstop_;
			//_irta[temp_sc].TI_.On_ = false;
			
			ks_change = true;
			break;
		default:;
		} // End switch

		//process input
		if (ks_change)
		{
			ret = process_input(_icda, _irta);
			if (ret != rt::OK) return ret;
			return rt::INPUT_RECEIVED;
		}
		else
		{
			//ret = reset_ks(KS_);
			//ret = reset_ks(KSprev_);
			return rt::INPUT_NOT_RECEIVED;
		}
	} // End while

	//return rt::OK;
	return rt::INPUT_NOT_RECEIVED;
}

ss::rt ss::InputController::process_input(ArrICD& _icda, ArrIRT& _irta)
{
	// 7/1/22 - need to add timestamps to this...
	rt ret = rt::INITIAL;

	for (size_t icd_i=0; icd_i<_icda.size(); ++icd_i)
	{
		ICD temp_icd = _icda[icd_i];
		for (size_t icv_i = 0; icv_i < temp_icd.size(); ++icv_i)
		{
			ICV temp_cv = temp_icd[icv_i];
			size_t temp_sc = CM_[temp_cv].K;
			_irta[icd_i].Flags_[icv_i] = SC_[temp_sc];
		}
	}
	return rt::OK;
}

ss::rt ss::InputController::init_locals()
{
	rt ret = rt::INITIAL;

	return rt::OK;
}
