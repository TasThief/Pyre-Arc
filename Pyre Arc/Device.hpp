#pragma once
#include "Servo.hpp"
#include "DeviceInspector.hpp"

namespace Engine {

	class Device : Servo
	{
	private:
		vk::Device& device;

		vk::PhysicalDevice PickPhysicalDevice(const vk::Instance& instance, const vk::SurfaceKHR& surface, const PhysicalDeviceRequestIndexes& requestedFeatures);

	public:
		Device(Foundation & f);

		~Device();
	};

}