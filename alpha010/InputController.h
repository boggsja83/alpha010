#pragma once

#include "ALL.h"
#include "SDLwrapper.h"

#include <array>

#include "InputContext.h"
#include "ControlMap.h"

#include "Timer.h"
#include "InputProp.h"

//context definitions - passed through by object calling input
//#include "ICDengMenu.h"
//#include "ICDtest.h"
//#include "ICDtest2.h"

/*--------------------------------------------------*/
namespace ss
/*--------------------------------------------------*/
{

	static size_t constexpr	size_SC = sizeof(bool) * 300;// SDL_NUM_SCANCODES;
	typedef std::array<bool, size_SC> Flags_SC;

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
			:	SC_({})
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
		//rt			reset_flags(Flags_SC&);
		//rt			reset_flags(Flags_IR&);
		//rt			copy_flags(Flags_SC&, Flags_SC&);
		//rt			copy_flags(Flags_IR&, Flags_IR&);
		//rt			set_irt(ICD&, IRT&);
		//rt			set_irt(ArrICD&, ArrIRT&);
		rt			process_input(ArrICD&, ArrIRT&);
		//rt			process_input(ArrIC&, Flags_IR&);

	public:
		//rt			input(ArrIC&, Flags_IR&);
		rt			input(ArrICD&, ArrIRT&);

		//ICD			get_icd(InputContext);
		//size_t		get_icd_i(InputContext);
		//bool		icd_has_icv(ICD,ICV);

		//inline rt	push_icd(ICD _icd)
		//{
		//	ICDvec_.push_back(_icd);
		//	return rt::OK;
		//}
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*----------------Member variables------------------*/
		/*--------------------------------------------------*/
	private:
		// actual highest value is 284? i believe
		// 0,4-282 are sdl indices, 283,284 = user hardware defined?
	
		//static constexpr char const* const rr="ddd";


		Flags_SC	SC_;
		//Flags_SC	SCprev_;

		ControlMap	CM_;

		//ArrTMR		TMR_;	// 7/1/22 - this should not be used
		//std::vector<ICD>	ICDvec_;

	public:
		//Flags_SC	Blank_SC_;
		//ICDblank	Blank_ICD_;
		//Flags_IR	Blank_IRAO_;

		

		/*--------------------------------------------------*/


	}; // END	class InputController

} // END	namespace ss

