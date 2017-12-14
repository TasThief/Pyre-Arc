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

using namespace std;

#ifdef _DEBUG
#define COUT(message) cout<<message<<endl;
#else
#define COUT(message)
#endif

namespace Engine {

#ifdef _DEBUG
	class MemoryProfiler {
	public:
		inline MemoryProfiler() {}
		inline virtual ~MemoryProfiler(){
			COUT("Looking for memory leaks!")
			_CrtDumpMemoryLeaks();
		};
	};



	struct Requirement {
	public:
		inline static const MemoryProfiler profiler;

		inline static const vector<char*> layersNames = {
			"VK_LAYER_LUNARG_standard_validation"
		};

#else
	struct Requirement {
	public:
		inline static const vector<char*> layersNames = {};



#endif
		inline static const vector<char*> instanceExtensionsNames = {
			VK_KHR_SURFACE_EXTENSION_NAME,
			VK_KHR_WIN32_SURFACE_EXTENSION_NAME
		};

		inline static const int width  = 1280;
		inline static const int height = 720; 

	};

}