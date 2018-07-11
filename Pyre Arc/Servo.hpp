#pragma once
#include "Foundation.hpp"

namespace Engine {
	//Servos provides a RAII wrap for the building and destroying processes of a given vulkan element,
	//these objects are kept in the foundation, this master class also provides an reference to it
	class Servo
	{
	public:
		//Base Ctor only initialized the foundation reference
		inline Servo(Foundation & f) {};
	};

}
