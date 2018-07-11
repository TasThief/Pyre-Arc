#pragma once
#include "Servo.hpp"

namespace Engine {
	class Window : Servo
	{
	private:
		SDL_Window * & window;
	public:
		Window(Foundation & f); 

		virtual ~Window();
	};

}
