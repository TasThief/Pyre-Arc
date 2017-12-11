#pragma once
#include "Servo.hpp"
namespace Engine {
	class Surface : Servo
	{
	public:
		inline Surface(Foundation& f) : Servo(f)
		{
			try {
				SDL_SysWMinfo windowInfo;
				SDL_VERSION(&windowInfo.version);
				if (!SDL_GetWindowWMInfo(_window, &windowInfo)) {
					throw std::system_error(std::error_code(), "SDK window manager info is not available.");
				}

				if (windowInfo.subsystem == SDL_SYSWM_WINDOWS) {
					vk::Win32SurfaceCreateInfoKHR surfaceInfo = vk::Win32SurfaceCreateInfoKHR()
						.setHinstance(GetModuleHandle(NULL))
						.setHwnd(windowInfo.info.win.window);
					_surface = _instance.createWin32SurfaceKHR(surfaceInfo);
					COUT("Surface created")

				}
				else
					throw std::system_error(std::error_code(), "Unsupported window manager is in use.");
			}
			catch (const std::exception& e) {
				COUT("Failed to create Vulkan surface");
				cout << e.what() << endl;
			}
		};
		inline virtual~Surface()
		{
			_instance.destroySurfaceKHR(_surface);
			COUT("Surface destroyed")
		};
	};

}