#include "IO.h"

bool SFM::IO::ImportIMGs(SFMDataSet &dataSet, Path &imgDir, std::string imgType)
{
	boost::filesystem::path imgPath(imgDir);
	boost::filesystem::recursive_directory_iterator iter(imgDir);
	boost::filesystem::recursive_directory_iterator iterEnd;
	for (; iter != iterEnd; ++iter) {
		if (boost::filesystem::is_directory(*iter))
			continue;

		if (iter->path().extension().string() != imgType)
			continue;

		IMG img;
		img.m_imgPath = iter->path().string();
		img.m_imgName = iter->path().filename().string();
		dataSet.m_imgs.push_back(img);
	}

	return true;
};

bool SFM::IO::LoadImgBase(SFMDataSet &dataSet, ImgID imgid, bool grayFlags)
{
	int flags = grayFlags ? 0 : 1;
	dataSet.m_imgs[imgid].m_base = cv::imread(dataSet.m_imgs[imgid].m_imgPath, flags);

	return true;
}
