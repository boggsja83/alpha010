#include "ALL.h"
#include "Engine.h"

using namespace ss;

int main(int argc, char* argv[])
{
	system("cls");
	ss::engine sl1m;


	for (int i=0;i<=(int)ss::rt_ret_t::RET_T_COUNT;++i) log(i <<": "<<rt_ret_m[i]);
	

	SDL_Delay(2000);



	//sdl_ view_;
	//view_.draw();
 

	//int8_t a = 0x0;

	//int b = 254;

	////a = static_cast<int8_t>(b);
	//a = b;
	//a -= 1;
	//a = ~(a & a);

	//std::cout << a << std::endl;

	//printf("a=%x\n",a);


	//std::cout.setf(std::ios::hex, std::ios::basefield);  // set hex as the basefield
	//std::cout.setf(std::ios::showbase);                  // activate showbase
	//std::cout.setf(std::ios::showpos);
	//std::cout << 69 << a << '\n';
	//std::cout.unsetf(std::ios::showbase);  
	//std::cout << 69 << '\n';
	////std::cout.unsetf(std::ios::showpos);
	//std::cout << std::dec << a << '\n';



	return 0;
}
