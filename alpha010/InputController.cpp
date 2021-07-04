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
//{
//	//delete this function
//	
//
//	while (SDL_PollEvent(&Event_))
//	{
//		log("poll_event()");
//
//	}
//	//log("done polling");
//	//if (SDL_PollEvent(&Event_))
//	//	return rt::EVENT_PENDING;
//	//else
//	//	return rt::EVENT_NOT_PENDING;
//
//	return Event_;
//}

ss::rt ss::InputController::input(ArrIC& _arr, IRAO& _irao)
{
	SDL_Event		ev;
	SDL_Scancode	temp_sc = SDL_SCANCODE_UNKNOWN;
	rt				ret = rt::OK;
	bool			ks_change =	false;

	while (SDL_PollEvent(&ev))
	{
	//SDL_PollEvent(&ev);

		ks_change = false;
		temp_sc = ev.key.keysym.scancode;

		switch (ev.type)
		{
		case SDL_QUIT:
			return rt::QUIT;
		case SDL_KEYDOWN:
			KS_[temp_sc] = true;
			ks_change = true;
			break;
		case SDL_KEYUP:
			KS_[temp_sc] = false;
			ks_change = true;
			break;
		default:;
		} // End switch

		//process input
		if (ks_change)
		{
			ret = process_input(_arr, _irao);
			if (ret != rt::OK) return ret;
		}
		else
		{
			ret = reset_ks(KS_);
			ret = reset_ks(KSprev_);
		}
	} // End while

	return rt::INPUT_RECEIVED;
}

ss::rt ss::InputController::process_input(ArrIC& _ic, IRAO& _irao)
{
	size_t ir = 0;
	// look over each context in _ic
	for (size_t i_cxt=0;i_cxt<_ic.size();++i_cxt)
	{
		// get definition of current Context
		// if not IC::NONE

		IC temp_ic = _ic[i_cxt];
		if (temp_ic == IC::NONE)
		{
			//
		}
		else
		{
			// current Context definition
			ICD temp_icd = get_icd(temp_ic);
			if (temp_icd.IC_ == Blank_ICD_.IC_)
			{
				// definition not found->exit
			}
			else
			{
				// Context definition found
				// 
				// iterate each ICV
				for(size_t i_def=0; i_def<temp_icd.ICVvec_.size(); ++i_def)
				{
					// current ICV in ICD
					ICV temp_icv = temp_icd.ICVvec_[i_def];

					if (temp_icv == ICV::NONE)
					{
						//log("context: "<<(int)temp_ic<<" listing complete");
					}
					else
					{
						// valid ICV
						SDL_Scancode temp_sc = CM_.Map[(size_t)temp_icv].K;
						//log(
						//	"context: " << (size_t)temp_ic <<
						//	" value: " << (size_t)temp_icv <<
						//	" scancode: " << (size_t)temp_sc
						//);

						bool is_down = KS_[temp_sc];
						if (is_down)
						{
							//key is currently down
							
							log(
								"Context: " << (size_t)temp_ic <<
								" | Scancode: " << (size_t)temp_sc <<
								" | IRAO flag set: " << (size_t)temp_icv;
							);
							_irao[(size_t)temp_icv] = true;
						}
						else
						{
							//key not currently down
							//log((size_t)CM_.CM_[(size_t)temp_icv].V << " IS UP!");
							//log("not valid context key");

						} // confirm if KS_ true/false
					} // if valid context value
				} // for each context value
			}// If good context definition

		}// If good context
	}// End main for

	rt ret = rt::INITIAL;

	ret = copy_ks(KSprev_, KS_);
	ret = reset_ks(KS_);

	return rt::OK;
}

ss::ICD ss::InputController::get_icd(InputContext _ic)
{
	size_t i = get_icd_i(_ic);

	if (i == rerr_sizet)
		return Blank_ICD_;
	else
		return ICDvec_[i];
}

size_t ss::InputController::get_icd_i(InputContext _ic)
{
	for (size_t i = 0; i < ICDvec_.size(); ++i)
		{ if (ICDvec_[i].IC_ == _ic) { return i; } }

	return rerr_sizet;
}

bool ss::InputController::icd_contains_ic(ICD _icd, ICV _icv)
{
	for (size_t i=0;i<_icd.ICVvec_.size();++i)
	{
		if (_icv == _icd.ICVvec_[i])
			return true;
	}
	return false;
}

ss::rt ss::InputController::init_locals()
{
	rt ret = rt::INITIAL;

	ret = reset_ks(KS_);
	ret = reset_ks(KSprev_);
	
	ret = push_icd(ICD_t1());
	ret = push_icd(ICD_em());//do this in "level"?? (dynamically load contexts?) -maybe not
	ret = push_icd(ICD_t2());

	return rt::OK;
}

ss::rt ss::InputController::reset_ks(ArrKS& _ks)
{
	std::memcpy(&_ks, &Blank_KS_, size_KS);
	return rt::OK;
}

ss::rt ss::InputController::reset_irao(IRAO& _irao)
{
	std::memcpy(&_irao, &Blank_IRAO_, size_IRAO);
	return rt::OK;
}

ss::rt ss::InputController::copy_ks(ArrKS& _dst, ArrKS& _src)
{
	std::memcpy(&_dst, &_src, size_KS);
	return rt::OK;
}

ss::rt ss::InputController::copy_irao(IRAO& _dst, IRAO& _src)
{
	std::memcpy(&_dst, &_src, size_IRAO);
	return rt::OK;
}
