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

	typedef std::chrono::steady_clock SCT;
	/**************************************************/

	/**************************************************/
	struct Timer
	/**************************************************/
	{
		/**************************************************/
		/*********************Members**********************/
		/**************************************************/
		std::chrono::duration<long long, std::ratio<1,1000000000>>	Duration_;
		std::chrono::time_point<SCT> TPstart_;
		std::chrono::time_point<SCT> TPstop_;
		bool On_;
		/**************************************************/

		/**************************************************/
		/*********************Functions********************/
		/**************************************************/
		inline void start()
		/**************************************************/
		{
			if (On_) return;
			TPstart_ = SCT::now();
			On_ = true;
		}
		/**************************************************/
		inline void stop()
		/**************************************************/
		{
			if (!On_) return;
			TPstop_ = SCT::now();
			On_ = false;
			Duration_ = TPstop_ - TPstart_;
		}
		/**************************************************/

		/**************************************************/
		/***************Contructor/Destructor**************/
		/**************************************************/
		Timer():
			Duration_()
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

}
