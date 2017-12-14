#pragma once
#include "Servo.hpp"

namespace Engine {

	struct FamilyIndex {
		int index = -1;
		vk::QueueFamilyProperties info;

		bool validate(const vector<float>& request) {
			return (info.queueCount > request.size() && index != -1);
		};
		void test() {
			
		};
	};
	struct PhysicalDeviceInfo {
		vk::PhysicalDevice device;
		vk::PhysicalDeviceProperties properties;
		vector<vk::QueueFamilyProperties> qfp;
		inline PhysicalDeviceInfo(vk::PhysicalDevice newDevice){
			device = newDevice;
			properties = device.getProperties();
			qfp = device.getQueueFamilyProperties();
			
		};
	};
	class PhysicalDevice : Servo
	{
	public:
		inline PhysicalDevice(Foundation& f) : Servo(f) {
			vector<PhysicalDeviceInfo> infoList;
			for (const auto& device : _instance.enumeratePhysicalDevices())
				infoList.push_back(PhysicalDeviceInfo(device));

		};
		inline void RateDevice() {

		};
		inline ~PhysicalDevice() {
			
		};
	};
}