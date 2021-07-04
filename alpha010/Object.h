#pragma once

#include "ALL.h"

#include "InputContext.h"

namespace ss
{
	class Object
	{
	public:
		Object() { rt ret = init(); }
		~Object() { rt ret = destroy(); }

		inline rt init() 
		{
			IC_ = IC::TEST2;
			return rt::OK;
		};
		inline rt destroy() { return rt::OK; };

		inline rt input_rx(ICV _icv)//call this from STengMenu is my goal
		{
			log("input_rx("<<(size_t)_icv<<")");
			return rt::OK;
		}

		inline IC ic() { return IC_; }
		inline char const* text_name() { return Name_text_; };
		inline char const* common_name() { return Name_com_; }

	private:
		char const* Name_com_ = "object";
		char const* Name_text_ = "menu-main";
		InputContext	IC_;
	};
} // END	namespace ss
