#ifndef SFM_DATABASE_H
#define SFM_DATABASE_H

#include "Core.h"

NAMESPACE_START

class Point2d : public Kernel2D
{
public:
	ID point3dID;
};

class Point3d : public Kernel3D
{
public:
	using Track = std::map<ImageID, PointID>;

	Track track;
};

class Pos : public Kernel3D
{
public:
	BaseType R[9];
};

class CamInfo
{
public:
	BaseType K[9];
	BaseType K1, K2, P1, P2;
};

class Pointcloud
{
public:

private:
	std::vector<Point3d> points;
};

class Image;
class ImageInfo
{
public:
	Pos pos;
	CamInfo cam;
	Image* basePtr;
};

class DataBase : public Kernel
{
public:
	ImageInfo imgInfo;
	std::vector<Point2d> point2ds;
	Pointcloud pcl;
};

NAMESPACE_END
#endif // !SFM_DATABASE_H
