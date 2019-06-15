#ifndef __SFMIO_H__
#define __SFMIO_H__

#include <boost/filesystem.hpp>
#include "SFMDataSet.h"

namespace SFM
{
	namespace IO
	{
		/**
		  读取影像路径 + 影像名称
		*/
		bool ImportIMGs(SFMDataSet &dataSet, Path &imgDir, std::string imgType = "jpg");
		
		/**
		  加载指定影像到内存， 
		  grayFlags : 是否以灰度影像读入
		*/
		bool LoadImgBase(SFMDataSet &dataSet, ImgID imgid, bool grayFlags = true);
	}
}

#endif // __SFMIO_H__
