#pragma once
#include "Requirements.hpp"

namespace Servo {
	class Surface
	{
	private:
		vk::SurfaceKHR surface;

		vk::Instance& instance;
	public:
		operator vk::SurfaceKHR &();

		Surface(vk::Instance & instance, SDL_Window* & window); 

		virtual ~Surface();
	};
}