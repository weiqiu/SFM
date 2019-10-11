#ifndef SFM_TYPES_H
#define SFM_TYPES_H

#include <vector>
#include <string>
#include <map>

using BaseType = float;
using SizeType = size_t;
using ID = SizeType;
using ImageID = ID;
using PointID = ID;

#define NAMESPACE_START namespace sfm {
#define NAMESPACE_END }

NAMESPACE_START

class Kernel
{
public:

};

class Kernel2D
{
public:
	BaseType X;
	BaseType Y;
	BaseType Z;
};

class Kernel3D : public Kernel2D
{
public:
	BaseType Z;
};

NAMESPACE_END
#endif // !SFM_TYPES_H
