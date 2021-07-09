#include "ALL.h"
#include "Engine.h"

#include "Timer.h"

using namespace ss;

Timer TmrRun;

int main(int argc, char* argv[])
{
	TmrRun.start();

	system("cls");
	rt ret = rt::INITIAL;
	
	ss::Engine sl1m;

	ret = sl1m.loop();
	log("Engine::loop() ret: " << hr(ret));
	
	TmrRun.stop();
	NS temp_dur = TmrRun.Duration_;

	std::string time_output = hr(dur_ns(temp_dur));
	
	log("runtime: " << time_output << " [HH:MM:SS.MS.US]");	

	return 0;
}
