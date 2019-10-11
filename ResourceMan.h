#ifndef SFM_RESOURCE_MAN_H
#define SFM_RESOURCE_MAN_H

#include "DataBase.h"

NAMESPACE_START

class IO;
class ResourceMan
{
public:
	ResourceMan& GetInstance()
	{
		static ResourceMan resourceMan;
		return resourceMan;
	}

private:
	ResourceMan() {};
	~ResourceMan() {};

private:
	IO* imageIOer;
};

NAMESPACE_END
#endif // !SFM_RESOURCE_MAN_H
