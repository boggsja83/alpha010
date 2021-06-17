#include "Asset_Mgr.h"

uint8_t ss::asset_mgr::init()
{
	log("asset_mgr::init()");

	Vec_.reserve(10);	// start with max of 10 assets loaded at once
						// may need to manipulate this through later engine states



	return uint8_t();
}

uint8_t ss::asset_mgr::destroy()
{
	log("asset_mgr::destroy()");

	//std::vector<view_asset>::iterator itr;
	//uint8_t ret = 0xFF;

	//for (itr = Vec_.begin(); itr != Vec_.end(); ++itr)
	//{
	//	ret = del_a(itr->asset_name);
	//	if (ret) { return ret; }
	//}
	return del_all();
}

uint8_t ss::asset_mgr::del_all()
{
	uint8_t ret = 0xFF;
	while (!Vec_.empty())
	{
		// delete from tail - shouldnt need to with std::vector...
		// but should for performance?  most likely... bcuz vec will reposition elements
		// prob just changes pointer internally...
		
		//ret = del_a(Vec_[Vec_.size()-1].asset_name);
		if (ret) { return ret; }//prob going to comment this out or handle error more eloquent
	}
	return ret;
}

