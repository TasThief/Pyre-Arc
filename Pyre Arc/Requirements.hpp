#pragma once
#define VK_USE_PLATFORM_WIN32_KHR
#define SDL_MAIN_HANDLED

#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <vulkan/vulkan.hpp>

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <array>
#include <memory>
#include <functional>

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

using namespace std;
#ifdef _DEBUG
#define COUT(message) cout<<message<<endl;
#else
#define COUT(message)
#endif

namespace Engine {

	struct Requirements {
	public:
		const vector<char*> layers = {
			"VK_LAYER_LUNARG_standard_validation"
		};
		const vector<char*> instanceExtensions = {
				VK_KHR_SURFACE_EXTENSION_NAME,
				VK_KHR_WIN32_SURFACE_EXTENSION_NAME
		};
		const int width = 1280;
		const int height = 720;
		const uint32_t minimalApiVersion = VK_API_VERSION_1_0;
			
	};

}