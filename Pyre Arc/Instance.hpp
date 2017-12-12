#pragma once
#include "Servo.hpp"

namespace Engine {
	//This servo construct and deconstruct the vkInstance object, it checks if all required extensions are avaliable and triggers the validation layers aswell
	class Instance : Servo
	{
	private:
		//The engine requires these extensions to be built
		const vector<char*> requiredExtensions = {
			VK_KHR_SURFACE_EXTENSION_NAME, 
			VK_KHR_WIN32_SURFACE_EXTENSION_NAME
		};
		//If in debug mode trigger these validation layers
		const vector<char*> requiredLayers = {
#ifdef _DEBUG
			"VK_LAYER_LUNARG_standard_validation"
#endif
		};

		//Check if all required extensions are present for this aplication, if not throw an error
		inline void ValidateExtensions() {
			vector<string> missingExtensions = {};
			vector<vk::ExtensionProperties> iExtensions = vk::enumerateInstanceExtensionProperties();
			const auto begin = iExtensions.begin();
			const auto end = iExtensions.end();

			for (const auto& extensionName : requiredExtensions)
				if (find_if(begin, end, [&extensionName](vk::ExtensionProperties prop) { return   strcmp(prop.extensionName, extensionName); }) == end)
					missingExtensions.push_back(extensionName);

			if (missingExtensions.size() > 0) {
				string errorMessage = "[ERROR] Failed to find required extensions\n";
				for (const auto& extensionName : missingExtensions)
					errorMessage += "	- " + extensionName + "\n";
				throw vk::ExtensionNotPresentError(errorMessage);
			}
		}

	public:

		inline Instance(Foundation& f) : Servo(f)
		{
			//check if system has required extensions
			ValidateExtensions();

			//build application info struct, it contains info about this application...
			vk::ApplicationInfo appInfo = vk::ApplicationInfo()
				.setPApplicationName("Pyre Arc")
				.setApplicationVersion(1)
				.setApiVersion(VK_API_VERSION_1_0);

			//fill the instance creation form using requested layers, extensions and application info
			vk::InstanceCreateInfo instInfo = vk::InstanceCreateInfo()
				.setFlags(vk::InstanceCreateFlags())
				.setPApplicationInfo(&appInfo)
				.setEnabledExtensionCount(static_cast<uint32_t>(requiredExtensions.size()))
				.setPpEnabledExtensionNames(requiredExtensions.data())
				.setEnabledLayerCount(static_cast<uint32_t>(requiredLayers.size()))
				.setPpEnabledLayerNames(requiredLayers.data());

			try {
				//try to build the instance
				foundation.instance = vk::Instance(vk::createInstance(instInfo));
				COUT("[DONE] Instance")
			}
			catch (const std::exception& e) {
				//if something bad happens throw an error
				char* errorMsg = "[ERROR] Could not create a Vulkan Instance: " ;
				COUT(strcat(errorMsg, e.what()))
			}

		}

		inline virtual ~Instance()
		{
			//destroy the vkInstance
			foundation.instance.destroy();
			COUT("[UNDONE] Instance")
		}

	};
}
