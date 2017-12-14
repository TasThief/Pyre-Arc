#pragma once
#include "Foundation.hpp"

namespace Engine {
	//Servos provides a RAII wrap for the building and destroying processes of a given vulkan element,
	//these objects are kept in the foundation, this master class also provides an reference to it
	
	class Servo
	{

	//Shorthand for the vkInstance held within foundation
	#define _instance foundation.instance

	//Shorthand for the SDL_Window held within foundation
	#define _window foundation.window

	//Shorthand for the vkSurfaceKHR held within foundation
	#define _surface foundation.surface

	//Shorthand for the vkDevice held within foundation
	#define _physicalDevice foundation.physicalDevice

	public:
		//The foundation reference
		Foundation & foundation;

		//Base Ctor only initialized the foundation reference
		inline Servo(Foundation & f) : foundation(f) {}
	};

}
