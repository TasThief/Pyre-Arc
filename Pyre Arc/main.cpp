#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include "Core.hpp"

int main()
{
	{	Engine::Core core;
		core.Run();
	} //scope out the core to call for its destruction before the _CrtDumpMemoryLeaks

	_CrtDumpMemoryLeaks();
	return 0;
}

