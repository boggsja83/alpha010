#pragma once

#include <vector>
#include <array>
//#include <map>
//#include <tuple>
#include <utility>

#include "ALL.h"
#include "SDLwrapper.h"

#include "InputContext.h"
#include "ControlMap.h"

//context definitions
#include "ICDengMenu.h"

/*--------------------------------------------------*/
namespace ss
/*--------------------------------------------------*/
{
	typedef std::array<bool, 300> ArrKS;
	typedef std::array<InputContext, static_cast<size_t>(IC::IC_COUNT)> ArrIC;

/*--------------------------------------------------*/
	class InputController
/*--------------------------------------------------*/
	{
		/*--------------------------------------------------*/
		/*--------------Constructor/Destructor--------------*/
		/*--------------------------------------------------*/
	public:
		/*--------------------------------------------------*/
		InputController() 
			: KS_({true,1,1,1,1,1,1,1,1,1}), KSprev_({1,0,1,0,1,0,1,0,1,0,1}), Blanks_({})
		/*--------------------------------------------------*/
		{ 
			log("InputController()");
			rt ret = init();
		}
		/*--------------------------------------------------*/
		~InputController() 
		/*--------------------------------------------------*/
		{
			log("~InputController()");
			rt ret = destroy();
		}
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*-----------------Init/Destroy---------------------*/
		/*--------------------------------------------------*/
	private:
		rt init();
		rt init_locals();
		rt destroy();
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*----------------Member functions------------------*/
		/*--------------------------------------------------*/
	private:
		rt reset_ks(ArrKS&);
	public:
		rt input(ArrIC&);
		inline rt push_icd(ICD _icd)
		{
			ICDvec_.push_back(_icd);
			return rt::OK;
		}
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*----------------Member variables------------------*/
		/*--------------------------------------------------*/
	private:
		// actual highest value is 284? i believe
		// 0,4-282 are sdl indices, 283,284 = user hardware defined?
		ArrKS		KS_;
		ArrKS		KSprev_;
		ArrKS		Blanks_;
		ControlMap	CM_;

		std::vector<ICD>		ICDvec_;

		/*--------------------------------------------------*/


	}; // END	class InputController
} // END	namespace ss

