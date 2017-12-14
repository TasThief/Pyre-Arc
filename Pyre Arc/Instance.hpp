#pragma once
#include "Servo.hpp"

namespace Engine {
	//This servo construct and deconstruct the vkInstance object, it checks if all required extensions are avaliable and triggers the validation layers aswell
	class Instance : Servo
	{
	private:

		//Check if all required extensions are present for this aplication, if not throw an error
		inline void ValidateExtensions() {
			vector<string> missingExtensions = {};
			vector<vk::ExtensionProperties> iExtensions = vk::enumerateInstanceExtensionProperties();
			for (const auto& extensionName : requirements.instanceExtensions)
				if (find_if(iExtensions.begin(), iExtensions.end(), [&extensionName](vk::ExtensionProperties prop) { return strcmp(prop.extensionName, extensionName); }) == iExtensions.end())
					missingExtensions.push_back(extensionName);

			if (missingExtensions.size() > 0) {
				string errorMessage = "[ERROR] Failed to find required extensions\n";
				for (const auto& extensionName : missingExtensions)
					errorMessage += "	- " + extensionName + "\n";
				COUT(errorMessage);
				throw vk::ExtensionNotPresentError(errorMessage);
			}
		}

	public:

		inline Instance(Foundation & f, Requirements& r) : Servo(f, r)
		{
			//check if system has required extensions
			ValidateExtensions();
			//build application info struct, it contains info about this application...
			vk::ApplicationInfo appInfo = vk::ApplicationInfo()
				.setPApplicationName("Pyre Arc")
				.setApplicationVersion(1)
				.setApiVersion(requirements.minimalApiVersion);

			//fill the instance creation form using requested layers, extensions and application info
			vk::InstanceCreateInfo instInfo = vk::InstanceCreateInfo()
				.setFlags(vk::InstanceCreateFlags())
				.setPApplicationInfo(&appInfo)
				.setEnabledExtensionCount(static_cast<uint32_t>(requirements.instanceExtensions.size()))
				.setPpEnabledExtensionNames(requirements.instanceExtensions.data())
				.setEnabledLayerCount(static_cast<uint32_t>(requirements.layers.size()))
				.setPpEnabledLayerNames(requirements.layers.data());

			try {
				//try to build the instance
				_instance = vk::Instance(vk::createInstance(instInfo));
				COUT("[DONE] Instance")
			}
			catch (const std::exception& e) {
				//if something bad happens throw an error
				char* errorMsg = "[ERROR] Could not create a Vulkan Instance: ";
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
