#include <iostream>

#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "Window.h"

int main(int argc, char* argv [])
{
	std::cout << "Hello World" << std::endl;

	return 0;
}