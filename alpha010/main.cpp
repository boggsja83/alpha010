#include "ALL.h"
#include "Engine.h"

using namespace ss;

int main(int argc, char* argv[])
{
	system("cls");
	rt ret = rt::INITIAL;

	ss::engine sl1m;

	ret = sl1m.loop();
	if (ret != rt::SUCCESS) log(c2m(ret));





	//for (int i=0;i<(int)ss::ec_ret_t::COUNT_RET_T;++i)
	//	log(i <<": "<<c2m(i));

	//log(c2m(432));
	//int8_t jk = 127;
	//log(c2m(jk));
	//
	//int8_t j = rerr8;
	//std::cout << (int)j << std::endl;

	//std::cout.setf(std::ios::hex, std::ios::basefield);
	//std::cout.setf(std::ios::showbase);
	//std::cout.setf(std::ios::showpos);

	//int8_t yyy = -1;
	//std::cout << "yyy=" << static_cast<int>(yyy) << std::endl;
	//std::cout << "int8_t max is: " << static_cast<int>(INT8_MAX)<<std::endl;
	//std::cout << "int16_t max is: " << static_cast<int>(INT16_MAX)<<std::endl;
	//std::cout << "int8_t min is: " << static_cast<int>(INT8_MIN)<<std::endl;
	//std::cout << "int16_t min is: " << static_cast<int>(INT16_MIN)<<std::endl;

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
