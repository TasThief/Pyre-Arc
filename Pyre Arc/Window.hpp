#pragma once
#include "Servo.hpp"


namespace Engine {
	class Window : Servo
	{
	public:
		inline Window(Foundation & f, Requirements& r) : Servo(f,r)
		{
			if (SDL_Init(SDL_INIT_VIDEO) != 0) {
				COUT("[ERROR] Could not initialize SDL.")
			}
			_window = SDL_CreateWindow("Pyre Arc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, requirements.width, requirements.height, SDL_WINDOW_OPENGL);
			if (_window == NULL) {
				COUT("[ERROR] Could not create SDL window.")
			}
			else {
				COUT("[DONE] Window")
			}
		}
		inline virtual ~Window()
		{
			SDL_DestroyWindow(_window);
			SDL_Quit();
			COUT("[UNDONE] Window")
		}
	};

}
