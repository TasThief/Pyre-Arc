#pragma once
#include "Foundation.hpp"
#include "Instance.hpp"
#include "Window.hpp"
#include "Surface.hpp"

namespace Engine {

	class Core
	{
	public:
		Foundation foundation;
		Instance instance = Instance(foundation);
		Window window = Window(foundation);
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