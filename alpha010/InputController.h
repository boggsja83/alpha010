#pragma once

#include <vector>
#include <array>
//#include <map>
//#include <tuple>
//#include <utility>
#include <string>

#include "ALL.h"
#include "SDLwrapper.h"

#include "InputContext.h"
#include "ControlMap.h"

//context definitions
#include "ICDengMenu.h"
#include "ICDtest.h"
#include "ICDtest2.h"

/*--------------------------------------------------*/
namespace ss
/*--------------------------------------------------*/
{
	typedef std::array<bool, 300> ArrKS;
	typedef std::array<bool, static_cast<size_t>(ICV::ICV_COUNT)> IRAO;
	typedef std::array<InputContext, static_cast<size_t>(IC::IC_COUNT)> ArrIC;
	size_t constexpr size_KS = sizeof(bool) * 300;
	size_t constexpr size_IRAO = sizeof(bool)* static_cast<size_t>(ICV::ICV_COUNT);
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
			:	KS_({}),
				KSprev_({}),
				Blank_KS_({}),
				Blank_IRAO_({})
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
		rt			reset_ks(ArrKS&);
		rt			reset_irao(IRAO&);
		rt			copy_ks(ArrKS&, ArrKS&);
		rt			copy_irao(IRAO&, IRAO&);
		rt			process_input(ArrIC&, IRAO&);

	public:
		rt			input(ArrIC&, IRAO&);

		ICD			get_icd(InputContext);
		size_t		get_icd_i(InputContext);
		bool		icd_contains_icv(ICD,ICV);

		inline rt	push_icd(ICD _icd)
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

		ControlMap	CM_;
		std::vector<ICD>		ICDvec_;

	public:
		ArrKS		Blank_KS_;
		ICDblank	Blank_ICD_;
		IRAO		Blank_IRAO_;

		

		/*--------------------------------------------------*/


	}; // END	class InputController

} // END	namespace ss

