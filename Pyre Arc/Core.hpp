#pragma once
#include "Instance.hpp"
#include "Window.hpp"
#include "Surface.hpp"
#include "PhysicalDevice.hpp"

namespace Engine {

	class Core
	{
	public:
		//Foundation cointaining all vkObjects
		Foundation foundation;

		///Servos declarations
		Engine::Instance instance = Engine::Instance(foundation);
		Window window = Window(foundation);
		Engine::PhysicalDevice physicalDevice = Engine::PhysicalDevice(foundation);
		Surface surface = Surface(foundation);
		//...

		inline void Run()
		{
			bool stillRunning = true;
			while (stillRunning) {

				SDL_Event event;
				while (SDL_PollEvent(&event)) {

					switch (event.type) {

					case SDL_QUIT:
						stillRunning = false;
						break;

					default:
						// Do nothing.
						break;
					}
				}

				SDL_Delay(10);
			}
		};
	};
}