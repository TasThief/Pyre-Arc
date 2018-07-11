#pragma once
#include "Servo.hpp"

namespace Engine {
	class Surface : Servo
	{
	private:
		vk::SurfaceKHR& surface;

		vk::Instance& instance;
	public:
		Surface(Foundation & f); 

		virtual ~Surface();
	};
}