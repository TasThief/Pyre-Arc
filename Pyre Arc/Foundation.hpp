#pragma once
#include "Requirements.hpp"

namespace Engine {

	struct Foundation
	{
	public:

		vk::Instance instance;
		vk::SurfaceKHR surface;
		SDL_Window* window;
		vk::Device physicalDevice;
		//...
	};

};