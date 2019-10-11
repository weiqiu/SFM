#ifndef SFM_IO_H
#define SFM_IO_H

#include "Core.h"

NAMESPACE_START

class IO
{
public:
	IO() {};
	virtual ~IO() {};

	virtual bool Input(Kernel* base, const std::string &openPath = "") = 0;
	virtual bool Output(Kernel* base, const std::string &savePath = "") = 0;
};

class ImageIO
{
public:
	virtual bool Input(Kernel* base, const std::string &openPath = "")
	{
		return true;
	}

	virtual bool Output(Kernel* base, const std::string &savePath = "")
	{
		return true;
	}
};

NAMESPACE_END
#endif // !SFM_IO_H
