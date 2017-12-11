#pragma once
#include "Servo.hpp"
#define WIDTH 1280
#define HEIGHT 720

namespace Engine {
	class Window : Servo
	{
	public:
		inline Window(Foundation& f) : Servo(f)
		{
			if (SDL_Init(SDL_INIT_VIDEO) != 0) {
				COUT("Could not initialize SDL.")
			}
			_window = SDL_CreateWindow("Thiago Vulkan Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
			if (_window == NULL) {
				COUT("Could not create SDL window.")
			}
			else {
				COUT("Window created")
			}
		}
		inline virtual ~Window()
		{
			SDL_DestroyWindow(_window);
			SDL_Quit();
			COUT("Window Destroyed")
		}
	};

}
