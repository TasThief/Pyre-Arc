#pragma once
#include "Requirements.hpp"

namespace Servo {
	class Window {
	private:
		SDL_Window* window;

	public:
		Window(); 
		operator SDL_Window* &();
		virtual ~Window();
	};

}
