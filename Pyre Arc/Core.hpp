#pragma once
#include "Instance.hpp"
#include "Window.hpp"
#include "Surface.hpp"
#include "Device.hpp"

namespace Engine {

	class Core
	{
	public:
		//Resources each servo will get a reference to those so they can work with
		QueueManager queue;

		vk::Instance vkInstance;
		vk::SurfaceKHR vkSurface;
		SDL_Window* sdlWindow;
		vk::Device vkDevice;

		///Servo declarations
		Engine::Instance instance = Instance(vkInstance);
		Engine::Window window = Window(sdlWindow);
		Engine::Surface surface = Surface(vkSurface, vkInstance, sdlWindow);
		Engine::Device device = Device(vkDevice, vkInstance, vkSurface, queue);

		void Run();
	};
}




