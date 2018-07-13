#pragma once
#include "Foundation.hpp" 
#include "DeviceInspector.hpp"
#include "QueueManager.hpp"

namespace Engine {

	class Device
	{
	private:
		///reference do the device object
		vk::Device& device;

		///
		vk::PhysicalDevice PickPhysicalDevice(
			const vk::Instance& instance, 
			const vk::SurfaceKHR& surface, 
			const PhysicalDeviceRequestIndexes& requestedFeatures);

	public:
		Device(vk::Device & device, vk::Instance & instance, vk::SurfaceKHR & surface, QueueManager & queue);

		~Device();
	};

}