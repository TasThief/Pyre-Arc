#pragma once
#include "Foundation.hpp" 

namespace Engine {
	class Window
	{
	private:
		SDL_Window * & window;
	public:
		Window(SDL_Window* & window); 

		virtual ~Window();
	};

}
