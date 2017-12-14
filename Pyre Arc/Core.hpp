#pragma once
#include "Instance.hpp"
#include "Window.hpp"
#include "Surface.hpp"
#include "PhysicalDevice.hpp"
#define RESOURCES foundation, requirements
namespace Engine {

	class Core
	{
	public:
		//Resources each servo will get a reference to those so they can work with
		Foundation foundation;
		Requirements requirements;

		///Servo declarations
		Instance instance = Instance(RESOURCES);
		Window window = Window(RESOURCES);
		PhysicalDevice physicalDevice = PhysicalDevice(RESOURCES);
		Surface surface = Surface(RESOURCES);

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




