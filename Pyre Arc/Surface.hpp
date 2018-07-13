#pragma once
#include "Foundation.hpp" 

namespace Engine {
	class Surface
	{
	private:
		vk::SurfaceKHR& surface;

		vk::Instance& instance;
	public:
		Surface(vk::SurfaceKHR & surface, vk::Instance & instance, SDL_Window* & window); 

		virtual ~Surface();
	};
}