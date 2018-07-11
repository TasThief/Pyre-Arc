#include "Device.hpp"

vk::PhysicalDevice Engine::Device::PickPhysicalDevice(const vk::Instance& instance, const vk::SurfaceKHR& surface, const PhysicalDeviceRequestIndexes& requestedFeatures) {
	// Use an ordered map to automatically sort candidates by increasing score
	std::multimap<int, vk::PhysicalDevice> candidates;

	//sort devices using the device inspector
	for (const vk::PhysicalDevice& device : instance.enumeratePhysicalDevices())
		candidates.insert(std::make_pair(DeviceInspector(device, surface, requestedFeatures).RateFitness(), device));

	// Check if the best candidate is suitable at all
	if (candidates.rbegin()->first > 0)
		return candidates.rbegin()->second;
	else
		throw std::runtime_error("[ERROR] Failed to find a suitable GPU!");
};


Engine::Device::Device(Foundation & f) :Servo(f), device(f.device) {
	PhysicalDeviceRequestIndexes requestedFeatureIndexes = vk::PhysicalDeviceFeatures()
		.setGeometryShader(VK_TRUE)
		.setDepthClamp(VK_TRUE);

	vk::PhysicalDevice physicalDevice = PickPhysicalDevice(f.instance, f.surface, requestedFeatureIndexes);

	vector<vk::DeviceQueueCreateInfo> queueInfoList;
	f.queue.GetQueueCreationInfoList(physicalDevice, device, queueInfoList);

	/*		vk::DeviceCreateInfo deviceInfo = vk::DeviceCreateInfo()
	.setPQueueCreateInfos(queueInfoList.data())
	.setQueueCreateInfoCount(queueInfoList.size())
	//		.setEnabledExtensionCount()
	//	.setPpEnabledExtensionNames()
	.setPEnabledFeatures(VK_FALSE);

	device = physicalDevice.createDevice(deviceInfo);
	*/
	f.queue.InitializeHandlers(physicalDevice, device);

	COUT("[DONE] Device")
};

Engine::Device::~Device() {
	device.destroy();
	COUT("[UNDONE] Device")
};
	