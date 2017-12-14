#include "Core.hpp"

int main()
{
	{
		Engine::Core core;
		core.Run();
	}
	_CrtDumpMemoryLeaks();
	return 0;

}

