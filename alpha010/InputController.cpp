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
	SDL_Event ev;
	rt ret = rt::OK;

	while (SDL_PollEvent(&ev))
	{
		//log("size: "<<_arr.size());
		//for (size_t cxt = 0; cxt < _arr.size(); ++cxt)
		//{
		//	if (_arr[cxt] == IC::NONE)
		//	{
		//		log("IC::NONE hit");
		//		break;
		//	}
		//	else
		//		log("ICV: " << (int)_arr[cxt] << " key: " << CM_.CM_[(int)_arr[cxt]].K);
		//}
		SDL_Scancode temp_sc = ev.key.keysym.scancode;

		switch (ev.type)
		{
		case SDL_QUIT:
			return rt::QUIT;
		case SDL_KEYDOWN:
			KS_[temp_sc] = true;
			break;
		case SDL_KEYUP:
			KS_[temp_sc] = false;
			break;
		default:;
		} // End switch
	} // End while

	  //process input

	return rt::INPUT_RECEIVED;

	//SDL_Event temp_e;
	//bool waiting = true;
	//ET_.clear();

	//while(SDL_PollEvent(&temp_e))
	//{
		//auto ret = EventMap_.find(
		//	static_cast<SDL_EventType>(temp_e.type));

		//if (ret != EventMap_.end()) { log("processing event: " << ret->second); }			
		//else { log("***[unrecognized event]: " << temp_e.type); }
		// 
		//ET_.push_back(temp_e.type);
		//waiting = false;
		//
		//switch(temp_e.type)
		//{
		//	case SDL_QUIT:
		//		return rt::QUIT;
		//		break;
			//case SDL_KEYDOWN:
			//	return rt::INPUT_RECEIVED;
			//	break;
			//case SDL_KEYUP:
			//	break;
	//		default:
	//		break;
	//	}	
	//}

	//if(!waiting){ log("done processing "<<ET_.size()<<" events"); }

	//return rt::INPUT_RECEIVED;
}

ss::rt ss::InputController::init_locals()
{
	rt ret = rt::INITIAL;

	KS_ = std::move(KSprev_);
	ret = reset_ks(KS_);
	ret = reset_ks(KSprev_);
	

	ret = push_icd(ICD_em());//do this in "level"?? (dynamically load contexts?) -maybe not

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

	_ks = std::move(Blanks_);

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
