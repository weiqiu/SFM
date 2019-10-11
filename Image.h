#ifndef SFM_IMAGE_H
#define SFM_IMAGE_H

#include "Core.h"

NAMESPACE_START

class Image : public Kernel
{
public:
	using ValueType = float;

private:
	std::vector<ValueType> m_data;
};

NAMESPACE_END
#endif // !SFM_IMAGE_H
