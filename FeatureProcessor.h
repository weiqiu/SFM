#ifndef __FEATUREPROCESSOR_H__
#define __FEATUREPROCESSOR_H__

#include "SFMDataSet.h"

namespace SFM
{
	class FeatureProcessor
	{
	public:
		FeatureProcessor(double threld = 0.6);

		/**
		  提取影像的特征点，并建立描述子
		*/
		static bool Detect(ImgData &img, IMGKeyPoints &imgKeyPoints, Descriptor &descriptor);

		/**
		  根据左右影像特征描述子进行匹配
		*/
		bool Match(Descriptor &descriptorL, Descriptor &descriptorR);

		/**
		  获取匹配结果
		*/
		const IMGDMatch& GetMatches() { return m_matches; }

	private:
		bool __GoodMatch();

	private:
		double m_threld;
		IMGDMatch m_matches;
		
	};
}

#endif //!__FEATUREPROCESSOR_H__
