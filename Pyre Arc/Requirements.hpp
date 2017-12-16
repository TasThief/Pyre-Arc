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
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#else
#define COUT(message)
#endif

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define MINIMAL_API_VERSION VK_API_VERSION_1_0


