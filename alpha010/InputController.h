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
	//move some of these typedefs to InputContext.h?
	
	//size_t constexpr size_SC = sizeof(bool) * 300;
	//size_t const size_IRAO = sizeof(bool) * static_cast<size_t>(ICV::ICV_COUNT);
	//typedef std::array<bool, size_SC> ArrKS;
	//typedef std::array<bool, static_cast<size_t>(ICV::ICV_COUNT)> IRAO;
	//typedef std::array<InputContext, static_cast<size_t>(IC::IC_COUNT)> ArrIC;
	
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
			:	SC_({}),
				SCprev_({})
				//Blank_SC_({}),
				//Blank_IRAO_({})
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
		/*----------------Overloaded functions--------------*/
		/*--------------------------------------------------*/

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
		rt			reset_flags(Flags_SC&);
		rt			reset_flags(Flags_IR&);
		rt			copy_flags(Flags_SC&, Flags_SC&);
		rt			copy_flags(Flags_IR&, Flags_IR&);
		rt			process_input(ArrIC&, Flags_IR&);

	public:
		rt			input(ArrIC&, Flags_IR&);

		ICD			get_icd(InputContext);
		size_t		get_icd_i(InputContext);
		bool		icd_has_icv(ICD,ICV);

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
	
		//static constexpr char const* const rr="ddd";


		Flags_SC	SC_;
		Flags_SC	SCprev_;

		ControlMap	CM_;
		std::vector<ICD>	ICDvec_;

	public:
		//Flags_SC	Blank_SC_;
		//ICDblank	Blank_ICD_;
		//Flags_IR	Blank_IRAO_;

		

		/*--------------------------------------------------*/


	}; // END	class InputController

} // END	namespace ss

