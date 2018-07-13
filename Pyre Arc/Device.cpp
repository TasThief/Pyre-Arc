#include "Device.hpp"

vk::PhysicalDevice Servo::Device::PickPhysicalDevice(const vk::Instance& instance, const vk::SurfaceKHR& surface, const PhysicalDeviceRequestIndexes& requestedFeatures) {
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

Servo::Device::operator vk::Device &() {
	return device;
};

Servo::Device::Device(vk::Instance & instance, vk::SurfaceKHR & surface, QueueManager & queue) {
	PhysicalDeviceRequestIndexes requestedFeatureIndexes = vk::PhysicalDeviceFeatures()
		.setGeometryShader(VK_TRUE)
		.setDepthClamp(VK_TRUE);

	vk::PhysicalDevice physicalDevice = PickPhysicalDevice(instance, surface, requestedFeatureIndexes);

	vector<vk::DeviceQueueCreateInfo> queueInfoList;
	queue.GetQueueCreationInfoList(physicalDevice, device, queueInfoList);

	/*		vk::DeviceCreateInfo deviceInfo = vk::DeviceCreateInfo()
	.setPQueueCreateInfos(queueInfoList.data())
	.setQueueCreateInfoCount(queueInfoList.size())
	//		.setEnabledExtensionCount()
	//	.setPpEnabledExtensionNames()
	.setPEnabledFeatures(VK_FALSE);

	device = physicalDevice.createDevice(deviceInfo);
	*/
	queue.InitializeHandlers(physicalDevice, device);

	COUT("[DONE] Device")
};

Servo::Device::~Device() {
	device.destroy();
	COUT("[UNDONE] Device")
};
	