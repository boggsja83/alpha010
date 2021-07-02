#pragma once

#include "ALL.h"

#include "STengMenu.h"
#include "ViewController.h"
#include "InputController.h"

namespace ss
{
	class Engine :
		public State_Holder
	{
		/*--------------------------------------------------*/
		/*--------------State_Holder Members ---------------*/
		/*--------------------------------------------------*/
	public:
		//std::stack<state*> Stack_;
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*--------------State_Holder Functions--------------*/
		/*--------------------------------------------------*/
	public:
		//virtual rt pop_state();
		//virtual rt push_state(state*);

		//virtual rt enter_state();
		//virtual rt pause_state();
		//virtual rt resume_state();
		//virtual rt exit_state();

		//virtual rt input_state();
		//virtual rt draw_state();
		/*--------------------------------------------------*/
		
		/*--------------------------------------------------*/
		/*--------------Constructor/Destructor--------------*/
		/*--------------------------------------------------*/
	public:
		/*--------------------------------------------------*/
		Engine() : ST_em_(&View_, &Input_)
		/*--------------------------------------------------*/
		{
			log("Engine()");
			rt ret = init();
			log("Engine::init() ret: " << c2m(ret));
		}
		/*--------------------------------------------------*/
		~Engine()
		/*--------------------------------------------------*/
		{
			log("~Engine()");
			rt ret = destroy();
			log("Engine::destroy() ret: " << c2m(ret));
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
		/*--------------System Controllers------------------*/
		/*--------------------------------------------------*/
	private:
		ViewController		View_;
		InputController		Input_;
		/*--------------------------------------------------*/

		/*--------------------------------------------------*/
		/*--------------Engine States-----------------------*/
		/*--------------------------------------------------*/
	private:
		ST_eng_menu ST_em_;
		/*--------------------------------------------------*/

		// game loop
	public:
		rt loop();
	public:
		//rt input();
		//rt draw();
		//virtual rt input_state() override;
		bool On_;

	}; // END	engine class
} // END ss
