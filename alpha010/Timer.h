#pragma once

#include <chrono>
#include <ratio>

#include <sstream>

/**************************************************/
namespace ss
/**************************************************/
{
	/**************************************************/
	/*********************Typedefs*********************/
	/**************************************************/
	typedef std::chrono::nanoseconds NS;
	typedef std::chrono::microseconds US;
	typedef std::chrono::milliseconds MS;
	typedef std::chrono::seconds SEC;
	typedef std::chrono::minutes MIN;
	typedef std::chrono::hours HOUR;
	typedef std::chrono::steady_clock STDYCLK;
	typedef std::chrono::time_point<STDYCLK> TP;
	typedef std::chrono::duration<long long, std::ratio<1, 1000000000>> DUR_T;
	/**************************************************/


	/**************************************************/
	struct Timer
	/**************************************************/
	{
		/**************************************************/
		/******************** Members *********************/
		/**************************************************/
		//DUR_T	Duration_;
		//NS		Duration_;
		TP		TPstart_;
		TP		TPstop_;
		bool	On_;
		/**************************************************/

		/**************************************************/
		/******************** Functions *******************/
		/**************************************************/
		inline void start()
		/**************************************************/
		{
			if (On_) return;
			TPstart_ = STDYCLK::now();
			On_ = true;
		}
		/**************************************************/
		inline void stop()
		/**************************************************/
		{
			if (!On_) return;
			TPstop_ = STDYCLK::now();
			On_ = false;
			//Duration_ = TPstop_ - TPstart_;
		}
		/**************************************************/
		inline long long elapsed_t_ns()
		/**************************************************/
		{
			return (TPstop_ - TPstart_).count();
		}
		/**************************************************/
		inline long long current_t_ns()
		{
			TP n(STDYCLK::now());

			return (n - TPstart_).count();
		}
		/**************************************************/

		/**************************************************/
		
		/**************************************************/
		/******************** Overloads *******************/
		/**************************************************/
		/*void* operator=()
		{}*/
		/**************************************************/


		/**************************************************/
		/************** Contructor/Destructor *************/
		/**************************************************/
		Timer()//:
			//Duration_()
		{ 
			On_ = false;
		}
		~Timer() {}
		/**************************************************/
	};
	/**************************************************/
	
	// DURation
	template<typename T>
	static inline NS	dur_ns(T& _dur) { return std::chrono::duration_cast<NS>(_dur); }
	template<typename T>
	static inline US	dur_us(T& _dur) { return std::chrono::duration_cast<US>(_dur); }
	template<typename T>
	static inline MS	dur_ms(T& _dur) { return std::chrono::duration_cast<MS>(_dur); }
	template<typename T>
	static inline SEC	dur_sec(T& _dur){ return std::chrono::duration_cast<SEC>(_dur); }
	template<typename T>
	static inline MIN	dur_min(T& _dur){ return std::chrono::duration_cast<MIN>(_dur); }
	template<typename T>
	static inline HOUR	dur_hr(T& _dur) { return std::chrono::duration_cast<HOUR>(_dur); }	
	
	// COMPonent
	template<typename T>
	static inline NS	comp_ns(T& _dur) { return static_cast<NS>((dur_ns(_dur).count()  % 1000)/100); }
	template<typename T>
	static inline US	comp_us(T& _dur) { return static_cast<US>(dur_us(_dur).count() % 1000); }
	template<typename T>
	static inline MS	comp_ms(T& _dur) { return static_cast<MS>(dur_ms(_dur).count() % 1000); }
	template<typename T>
	static inline SEC	comp_sec(T& _dur){ return static_cast<SEC>(dur_sec(_dur).count() % 60); }
	template<typename T>
	static inline MIN	comp_min(T& _dur){ return static_cast<MIN>(dur_min(_dur).count() % 60); }
	template<typename T>
	static inline HOUR	comp_hr(T& _dur) { return static_cast<HOUR>(dur_hr(_dur).count()); }

	/**************************************************/
	static inline std::string hr(NS _ns)
	/**************************************************/
	{
		std::stringstream sstr;

		sstr.str("");

		sstr << comp_hr(_ns).count() << ':';
		sstr << comp_min(_ns).count() << ':';
		sstr << comp_sec(_ns).count() << '.';
		sstr << comp_ms(_ns).count() << '.';
		sstr << comp_us(_ns).count() << '.';
		sstr << comp_ns(_ns).count();

		return sstr.str();
	}

	///**************************************************/
	//static inline std::string hr(long long _raw)
	///**************************************************/
	//{
	//	std::stringstream sstr;

	//	sstr.str("");

	//	sstr << comp_hr(_raw).count() << ':';
	//	sstr << comp_min(_raw).count() << ':';
	//	sstr << comp_sec(_raw).count() << '.';
	//	sstr << comp_ms(_raw).count() << '.';
	//	sstr << comp_us(_raw).count() << '.';
	//	sstr << comp_ns(_raw).count();

	//	return sstr.str();
	//}

	// superfluous methinks...all info is in timer already
	//  looks like i was going to use it in input...  well see
	typedef struct TimerInfo
	{
		TP TPstart_;
		TP TPstop_;
		bool On_;

		TimerInfo() { On_ = false; }
		TimerInfo(Timer const& _rhs)
		{
			this->On_		= _rhs.On_;
			this->TPstart_	= _rhs.TPstart_;
			this->TPstop_	= _rhs.TPstop_;
		}

		~TimerInfo() {}

		// this may be subject with TimerInfo& return type, return *this...
		// after thinking, actually should be okay...
		// still needs testing in input tho 9/7/21
		TimerInfo& operator=(Timer const& _rhs)
		{
			this->On_ = _rhs.On_;
			this->TPstart_ = _rhs.TPstart_;
			this->TPstop_ = _rhs.TPstop_;
			
			return *this;
		}

		// add an elapsed_t func like timer
	} TI;

	static size_t constexpr	size_TMR = sizeof(bool) * 300;//SDL_NUM_SCANCODES;
	typedef std::array<Timer, size_TMR> ArrTMR;

} // END	namespace ss
