#pragma once
#include "Requirements.hpp"
#include "DeviceInspector.hpp"
#include "QueueManager.hpp"

namespace Servo {

	class Device
	{
	private:
		///reference do the device object
		vk::Device device;

		///
		vk::PhysicalDevice PickPhysicalDevice(
			const vk::Instance& instance, 
			const vk::SurfaceKHR& surface, 
			const PhysicalDeviceRequestIndexes& requestedFeatures);

	public:
		operator vk::Device &();

		Device(vk::Instance & instance, vk::SurfaceKHR & surface, QueueManager & queue);

		~Device();
	};

}