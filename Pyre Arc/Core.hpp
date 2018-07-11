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
		Foundation foundation;

		///Servo declarations
		Engine::Instance instance = Instance(foundation);
		Engine::Window window = Window(foundation);
		Engine::Surface surface = Surface(foundation);
		Engine::Device device = Device(foundation);

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




