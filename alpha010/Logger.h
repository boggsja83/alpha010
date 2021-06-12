// Simple Logger - outputs info to stderr
// Implementation by Jacob A. Boggs Dec 25 2020

// Credits to: Robert S. Barnes@stackoverflow.com/users
// https://stackoverflow.com/questions/6168107/how-to-implement-a-good-debug-logging-feature-in-a-project

//	TODO: file logging!
//	TODO: command line options!

// Example macro usage: 
//	Log entry with _LOG_DEFAULT_LL:
//
//	x = 5;
//	log("x = " << x);
//	
//	Log entry with specified log level:
//
//	if(x!=3)
//		_log(_LL::logERR1, "x should have been 3, not " << x);
//



	// Includes
#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

//#include "ODPEnums.h"

namespace ss
{

// Comment out following options to EXCLUDE ...
#define _LOG_OPT_ON		//	... logging entirely
#define _LOG_OPT_LLN	//	... log line number
//#define _LOG_OPT_LL		//	... log level
#define _LOG_OPT_FN		//	... file name
#define _LOG_OPT_FLN	//	... file line number

// Log level enum _LL
	enum class	_LL { logINF1, logDBG1, logERR1, logALRT1 };
	// _LL::logINF1		general information
	// _LL::logDBG1		debug information
	// _LL::logERR1		error information
	// _LL::logALRT1	severe information

	namespace sl
	{
		// Track number of log entries that have been made
		static int _LOG_LNC = 0;
	}

#define _LOG_DEFAULT_LL _LL::logDBG1	// Default log-entry log-level if not specified
#define _LOG_MAX_LEVEL _LL::logALRT1	// Maximum log-level for a log entry
#define _LOG_FILE_NAME __FILE__			// Used for getting file name of calling function
#define _LOG_FILE_LINE __LINE__			// Used for getting file line number of calling function

	class Logger
	{
	public:
		Logger(_LL _ll)
		{
#ifdef _LOG_OPT_LLN
			++sl::_LOG_LNC;
#endif
			this->LL = _ll;
		}

		~Logger()
		{
			std::ostringstream ss;

#ifdef _LOG_OPT_LLN
			ss << std::setw(3) << std::right << sl::_LOG_LNC;
#ifndef _LOG_OPT_LL
			ss << '|';
#endif
#endif

#ifdef _LOG_OPT_LL
			ss << '|' << (int)this->LL << '|';
#endif

#ifdef _LOG_OPT_FN
			ss << std::setw(20) << std::left << _LOG_PARSE_FILE_NAME(_buffer.str());
			//ss << std::setw(15) << std::left << _LOG_PARSE_FILE_NAME(_buffer.str());
#endif

#ifdef _LOG_OPT_FLN
			ss << "L:" << std::setw(4) << std::left << _LOG_PARSE_FILE_LINE(_buffer.str());
#endif

			ss << _LOG_PARSE_LOG_INFO(_buffer.str());

			ss << std::endl;
			_buffer << std::endl;	// TODO check documentation to see if ostringstream should terminate like this

			std::cerr << ss.str();
		}

		// Overloaded operator<< to stream info directly to _buffer
		template <typename T>
		Logger& operator<<(T const& _rhs)
		{
			this->_buffer << _rhs;
			return *this;
		}

		// A crude function to trim file name from full path
		std::string _LOG_TFN(std::string _b)
		{
			return _b.substr(_b.find_last_of('\\') + 1);
		}

		// Parse out file name from buffer
		std::string _LOG_PARSE_FILE_NAME(std::string _b)
		{
			return _LOG_TFN(_b.substr(0, _b.find('*')));
		}

		// Parse out file line from buffer
		std::string _LOG_PARSE_FILE_LINE(std::string _b)
		{
			int pos1 = _b.find('*');
			int pos2 = _b.find('*', pos1 + 1);

			return _b.substr(pos1 + 1, pos2 - pos1 - 1);
		}

		// Parse out log info from buffer
		std::string _LOG_PARSE_LOG_INFO(std::string _b)
		{
			int pos1 = _b.find('*');

			return _b.substr((_b.find('*', pos1 + 1)) + 1);
		}

		_LL LL;	// This log entry's log level

	private:
		std::ostringstream _buffer;
	};

	// Macro for log notation with log level conditional
	// Change conditional here for different display options
	//	e.g. Display only entries with specified log level
	// Default: 
	//	do not display entries with log levels higher than _LOG_MAX_LEVEL
	//
#ifdef _LOG_OPT_ON

#define _log(level, info) \
	if(level > _LOG_MAX_LEVEL) {} \
		else Logger(level) << \
		_LOG_FILE_NAME << '*' << \
		_LOG_FILE_LINE << '*' << \
		info

#define log(info) \
	if(_LOG_DEFAULT_LL > _LOG_MAX_LEVEL) {} \
		else Logger(_LOG_DEFAULT_LL) << \
		_LOG_FILE_NAME << '*' << \
		_LOG_FILE_LINE << '*' << \
		info

#else
#define _log(level,info) {}
#define log(info) {} // TODO: check the running time of "{}" sometime...
#endif

} // END namespace ss