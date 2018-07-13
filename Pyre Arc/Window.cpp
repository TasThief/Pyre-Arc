#include "Window.hpp"

Engine::Window::Window(SDL_Window* & window) : window(window)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		COUT("[ERROR] Could not initialize SDL.")
	}
	window = SDL_CreateWindow("Pyre Arc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
	if (window == NULL) {
		COUT("[ERROR] Could not create SDL window.")
	}
	else {
		COUT("[DONE] Window")
	}
};
Engine::Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
	COUT("[UNDONE] Window")
};