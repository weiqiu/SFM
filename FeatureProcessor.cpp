
#include "FeatureProcessor.h"

SFM::FeatureProcessor::FeatureProcessor(double threld = 0.6)
{
	m_threld = threld;
}

bool SFM::FeatureProcessor::Detect(ImgData &img, IMGKeyPoints &imgKeyPoints, Descriptor &descriptor)
{
	cv::Ptr<cv::ORB> orbDescriptor = cv::ORB::create();
	orbDescriptor->detect(img, imgKeyPoints, descriptor);
	return true;
}

bool SFM::FeatureProcessor::Match(Descriptor &descriptorL, Descriptor &descriptorR)
{
	m_matches.clear();
	cv::Ptr<cv::DescriptorMatcher> d_matcher = cv::DescriptorMatcher::create(cv::NORM_L2);
	d_matcher->match(descriptorL, descriptorR, m_matches);
	__GoodMatch();

	return true;
}

bool SFM::FeatureProcessor::__GoodMatch()
{
	double max_dist = -1.0;
	double min_dist = 10e+10;
	
	double dist = 0;

	for (size_t i = 0; i < m_matches.size(); i++) {
		dist = m_matches[i].distance;
		if (dist < min_dist) {
			min_dist = dist;
		}
		if (dist > max_dist) {
			max_dist = dist;
		}
	}

	IMGDMatch goodMatches;
	for (int i = 0; i < m_matches.size(); i++) {
		if (m_matches[i].distance <m_threld * max_dist) {
			goodMatches.push_back(m_matches[i]);
		}
	}

	m_matches = goodMatches;
	return true;
}
