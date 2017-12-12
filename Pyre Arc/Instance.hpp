#pragma once
#include "Servo.hpp"

namespace Engine {
	class Instance : Servo
	{
	public:
		inline Instance(Foundation& f) : Servo(f)
		{
			vector<const char*> extensions;
			extensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
			extensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);

			std::vector<const char*> layers;
#if defined(_DEBUG)
			layers.push_back("VK_LAYER_LUNARG_standard_validation");
#endif

			vk::ApplicationInfo appInfo = vk::ApplicationInfo()
				.setPApplicationName("Test Build")
				.setApplicationVersion(1)
				.setPEngineName("Pyre Arc")
				.setEngineVersion(1)
				.setApiVersion(VK_API_VERSION_1_0);

			vk::InstanceCreateInfo instInfo = vk::InstanceCreateInfo()
				.setFlags(vk::InstanceCreateFlags())
				.setPApplicationInfo(&appInfo)
				.setEnabledExtensionCount(static_cast<uint32_t>(extensions.size()))
				.setPpEnabledExtensionNames(extensions.data())
				.setEnabledLayerCount(static_cast<uint32_t>(layers.size()))
				.setPpEnabledLayerNames(layers.data());

			try {
				foundation.instance = vk::Instance(vk::createInstance(instInfo));
				COUT("Instance created")
			}
			catch (const std::exception& e) {
				COUT("Could not create a Vulkan instance")
					cout << e.what();
			}

		}
		inline virtual ~Instance()
		{
			foundation.instance.destroy();
			COUT("Instance destroyed")
		}
	};
}
