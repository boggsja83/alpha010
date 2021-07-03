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

ss::rt ss::InputController::input(ArrIC& _arr)
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
			ret = process_input(_arr);
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

ss::rt ss::InputController::process_input(ArrIC& _ic)
{
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
						SDL_Scancode temp_sc = CM_.CM_[(size_t)temp_icv].K;
						//log(
						//	"context: " << (size_t)temp_ic <<
						//	" value: " << (size_t)temp_icv <<
						//	" scancode: " << (size_t)temp_sc
						//);

						bool is_down = KS_[temp_sc];
						if (is_down)
						{
							//key is currently down
							//log((size_t)CM_.CM_[(size_t)temp_icv].V << " IS DOWN!");
							log(
								"Context: "		<<(size_t)temp_ic	<<
								" Scancode: "	<<(size_t)temp_sc
							);
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

	ret = copy_ks(KSprev_, KS_, size_KS);
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

ss::rt ss::InputController::init_locals()
{
	rt ret = rt::INITIAL;

	ret = reset_ks(KS_);
	ret = reset_ks(KSprev_);
	
	ret = push_icd(ICD_t1());
	ret = push_icd(ICD_em());//do this in "level"?? (dynamically load contexts?) -maybe not
	ret = push_icd(ICD_t2());

	//for (size_t i =0; i<KSprev_.size();++i)
	//{
	//	KSprev_[i] = false;
	//}
	return rt::OK;
}

ss::rt ss::InputController::reset_ks(ArrKS& _ks)
{
	//try to use std::move with std::array
	//if i cant get this to work, eliminate 
	//std::array and use c++ array

	//_ks = std::move(Blank_KS_);

	std::memcpy(&_ks, &Blank_KS_, size_KS);

	return rt::OK;
}

ss::rt ss::InputController::copy_ks(ArrKS& _dst, ArrKS& _src, size_t _size)
{
	std::memcpy(&_dst,&_src,_size);
	return rt::OK;
}

//ss::rt ss::InputController::init_event_map()
//{
//	EventMap_.insert({ SDL_FIRSTEVENT				, "SDL_FIRSTEVENT" });
//	EventMap_.insert({ SDL_QUIT						, "SDL_QUIT" });
//	EventMap_.insert({ SDL_APP_TERMINATING			, "SDL_APP_TERMINATING" });
//	EventMap_.insert({ SDL_APP_LOWMEMORY			, "SDL_APP_LOWMEMORY" });
//	EventMap_.insert({ SDL_APP_WILLENTERBACKGROUND	, "SDL_APP_WILLENTERBACKGROUND" });
//	EventMap_.insert({ SDL_APP_DIDENTERBACKGROUND	, "SDL_APP_DIDENTERBACKGROUND" });
//	EventMap_.insert({ SDL_APP_WILLENTERFOREGROUND	, "SDL_APP_WILLENTERFOREGROUND" });
//	EventMap_.insert({ SDL_APP_DIDENTERFOREGROUND	, "SDL_APP_DIDENTERFOREGROUND" });
//	EventMap_.insert({ SDL_DISPLAYEVENT				, "SDL_DISPLAYEVENT" });
//	EventMap_.insert({ SDL_WINDOWEVENT				, "SDL_WINDOWEVENT" });
//	EventMap_.insert({ SDL_SYSWMEVENT				, "SDL_SYSWMEVENT" });
//	EventMap_.insert({ SDL_KEYDOWN					, "SDL_KEYDOWN" });
//	EventMap_.insert({ SDL_KEYUP					, "SDL_KEYUP" });
//	EventMap_.insert({ SDL_TEXTEDITING				, "SDL_TEXTEDITING" });
//	EventMap_.insert({ SDL_TEXTINPUT				, "SDL_TEXTINPUT" });
//	EventMap_.insert({ SDL_KEYMAPCHANGED			, "SDL_KEYMAPCHANGED" });
//	EventMap_.insert({ SDL_MOUSEMOTION				, "SDL_MOUSEMOTION" });
//	EventMap_.insert({ SDL_MOUSEBUTTONDOWN			, "SDL_MOUSEBUTTONDOWN" });
//	EventMap_.insert({ SDL_MOUSEBUTTONUP			, "SDL_MOUSEBUTTONUP" });
//	EventMap_.insert({ SDL_MOUSEWHEEL				, "SDL_MOUSEWHEEL" });
//	EventMap_.insert({ SDL_JOYAXISMOTION			, "SDL_JOYAXISMOTION" });
//	EventMap_.insert({ SDL_JOYBALLMOTION			, "SDL_JOYBALLMOTION" });
//	EventMap_.insert({ SDL_JOYHATMOTION				, "SDL_JOYHATMOTION" });
//	EventMap_.insert({ SDL_JOYBUTTONDOWN			, "SDL_JOYBUTTONDOWN" });
//	EventMap_.insert({ SDL_JOYBUTTONUP				, "SDL_JOYBUTTONUP" });
//	EventMap_.insert({ SDL_JOYDEVICEADDED			, "SDL_JOYDEVICEADDED" });
//	EventMap_.insert({ SDL_JOYDEVICEREMOVED			, "SDL_JOYDEVICEREMOVED" });
//	EventMap_.insert({ SDL_CONTROLLERAXISMOTION		, "SDL_CONTROLLERAXISMOTION" });
//	EventMap_.insert({ SDL_CONTROLLERBUTTONDOWN		, "SDL_CONTROLLERBUTTONDOWN" });
//	EventMap_.insert({ SDL_CONTROLLERBUTTONUP		, "SDL_CONTROLLERBUTTONUP" });
//	EventMap_.insert({ SDL_CONTROLLERDEVICEADDED	, "SDL_CONTROLLERDEVICEADDED" });
//	EventMap_.insert({ SDL_CONTROLLERDEVICEREMOVED	, "SDL_CONTROLLERDEVICEREMOVED" });
//	EventMap_.insert({ SDL_CONTROLLERDEVICEREMAPPED	, "SDL_CONTROLLERDEVICEREMAPPED" });
//	EventMap_.insert({ SDL_FINGERDOWN				, "SDL_FINGERDOWN" });
//	EventMap_.insert({ SDL_FINGERUP					, "SDL_FINGERUP" });
//	EventMap_.insert({ SDL_FINGERMOTION				, "SDL_FINGERMOTION" });
//	EventMap_.insert({ SDL_DOLLARGESTURE			, "SDL_DOLLARGESTURE" });
//	EventMap_.insert({ SDL_DOLLARRECORD				, "SDL_DOLLARRECORD" });
//	EventMap_.insert({ SDL_MULTIGESTURE				, "SDL_MULTIGESTURE" });
//	EventMap_.insert({ SDL_CLIPBOARDUPDATE			, "SDL_CLIPBOARDUPDATE" });
//	EventMap_.insert({ SDL_DROPFILE					, "SDL_DROPFILE" });
//	EventMap_.insert({ SDL_DROPTEXT					, "SDL_DROPTEXT" });
//	EventMap_.insert({ SDL_DROPBEGIN				, "SDL_DROPBEGIN" });
//	EventMap_.insert({ SDL_DROPCOMPLETE				, "SDL_DROPCOMPLETE" });
//	EventMap_.insert({ SDL_AUDIODEVICEADDED			, "SDL_AUDIODEVICEADDED" });
//	EventMap_.insert({ SDL_AUDIODEVICEREMOVED		, "SDL_AUDIODEVICEREMOVED" });
//	EventMap_.insert({ SDL_SENSORUPDATE				, "SDL_SENSORUPDATE" });
//	EventMap_.insert({ SDL_RENDER_TARGETS_RESET		, "SDL_RENDER_TARGETS_RESET" });
//	EventMap_.insert({ SDL_RENDER_DEVICE_RESET		, "SDL_RENDER_DEVICE_RESET" });
//	EventMap_.insert({ SDL_USEREVENT				, "SDL_USEREVENT" });
//	EventMap_.insert({ SDL_LASTEVENT				, "SDL_LASTEVENT" });
//
//	return rt::OK;
//}
