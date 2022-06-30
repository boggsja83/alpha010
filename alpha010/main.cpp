#include "ALL.h"
#include "Engine.h"

#include "Timer.h"

using namespace ss;

//Timer TmrRun;

int main(int argc, char* argv[])
{
	Timer TmrRun;
	TmrRun.start();

	system("cls");
	rt ret = rt::INITIAL;
	
	ss::Engine sl1m;

	ret = sl1m.loop();
	log("Engine::loop() ret: " << hr(ret));
	
	TmrRun.stop();

	// test TimerInfo
		
	//TI test = TmrRun; //constructor [operator()(Timer const& _rhs)??]
	//test = TmrRun; // operator=

	NS temp_dur = TmrRun.TPstop_ - TmrRun.TPstart_;

	long long test_dur = TmrRun.elapsed_t_ns();

	std::string time_output = hr(dur_ns(temp_dur));
	//std::string time_output2 = hr(test_dur);
	
	
	log("runtime: " << time_output << " [HH:MM:SS.MS.US]");	
	log("runtime: " << test_dur << " [HH:MM:SS.MS.US]");

	return 0;
}

//
//__declspec(noinline)
//bool is_stack_available(size_t amount)
//{
//	__try
//	{
//		_alloca(amount);
//		return true;
//	}
//	__except (
//		GetExceptionCode() == EXCEPTION_STACK_OVERFLOW
//		? EXCEPTION_EXECUTE_HANDLER
//		: EXCEPTION_CONTINUE_SEARCH)
//	{
//		_resetstkoflw();
//		return false;
//	}
//}
