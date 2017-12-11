#pragma once
// Enable the WSI extensions
#if defined(__ANDROID__)
#define VK_USE_PLATFORM_ANDROID_KHR
#elif defined(__linux__)
#define VK_USE_PLATFORM_XLIB_KHR
#elif defined(_WIN32)
#define VK_USE_PLATFORM_WIN32_KHR
#endif

#define SDL_MAIN_HANDLED

//rendering stuff
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <vulkan/vulkan.hpp>

namespace Engine {

	struct Foundation
	{
	public:
		vk::Instance instance;
		vk::SurfaceKHR surface;
		SDL_Window* window;
		//...
	};

};