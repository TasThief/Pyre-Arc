#pragma once
#include "Foundation.hpp"
#include <vector>
#include <iostream>

using namespace std;

#ifdef _DEBUG
#define COUT(message) cout<<#message<<endl;
#else
#define COUT(message)
#endif

namespace Engine {
	class Component
	{
	//Shorthand for the vkInstance held within foundation
	#define _instance foundation.instance

	//Shorthand for the SDL_Window held within foundation
	#define _window foundation.window

	//Shorthand for the vkSurfaceKHR held within foundation
	#define _surface foundation.surface

	public:
		Foundation & foundation;
		inline Component(Foundation & f) : foundation(f) {}
	};

}
