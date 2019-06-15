#ifndef __SFMDATASET_H__
#define __SFMDATASET_H__

#include <vector>
#include <opencv2/opencv.hpp>

namespace SFM 
{
	using Index = size_t;
	using ImgID = Index;
	using KeyPointID = Index;
	using Point3DID = Index;
	using CamID = Index;
	using PosID = Index;
	using ImgData = cv::Mat;
	using Scalar = double;

	using Path = std::string;

	using CameraMat = cv::Mat_<Scalar>;
	using RotateMat = cv::Mat_<Scalar>;
	using ProjectMat = cv::Mat_<Scalar>;
	using ImgView = std::map<KeyPointID, Point3DID>;
	using ImgAndKeyPointID = std::pair<ImgID, KeyPointID>;
	using Point3DView = std::vector<ImgAndKeyPointID>;

	class Point3D
	{
	public:
		using Color = cv::Scalar;
		using Point = cv::Point3d;	

		Point m_point;
		Color m_color;
		Point3DView m_point3DView;
	};

	class PointCloud
	{
	public:
		using Point3DS = std::vector<Point3D>;
		
		Point3DS m_point3Ds;
	};

	class Camera
	{
	public:
		Scalar m_f;
		Scalar m_x0;
		Scalar m_y0;

		Scalar m_k1;
		Scalar m_k2;
		Scalar m_k3;
		Scalar m_p1;
		Scalar m_p2;
		Scalar m_p3;

		CameraMat m_K;
	};

	class Pos
	{
	public:
		Scalar m_x;
		Scalar m_y;
		Scalar m_z;
		RotateMat m_R;
	};

	class IMG
	{
	public:
		Path m_imgPath;
		Path m_imgName;
		ImgData m_base;
		ProjectMat m_P;

		ImgID m_preImgID;
		ImgID m_imgID;
		ImgID m_nextImgID;
		CamID m_camID;
		PosID m_posID;
	};

	class SFMDataSet
	{
	public:
		using IMGVec = std::vector<IMG>;

		IMGVec m_imgs;
		PointCloud m_PointCloud;
	};

	inline bool IsVaildID(Index id) { return id != 0x7FFFFFFF; };
}


#endif // !__SFMDATASET_H__
