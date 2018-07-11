#pragma once
#include "Requirements.hpp"
#include "QueueManager.hpp"

namespace Engine {

	struct Foundation
	{
	public:

		QueueManager queue;

		vk::Instance instance;
		vk::SurfaceKHR surface;
		SDL_Window* window;
		vk::Device device;
		//...
	};

};