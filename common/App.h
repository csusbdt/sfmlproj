#ifndef APP_APP_H
#define APP_APP_H

#include "precompile.h"

class App
{
public:
	App() { }
	void run();
    std::string getResourcePath();  // implemented in platform code (outside of common)

private:
	DISALLOW_COPY_AND_ASSIGN(App);
};

#endif
