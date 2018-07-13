#pragma once
#include "Requirements.hpp"

namespace Servo {
	struct QueueFamilyPropertiesExt {
		const uint32_t count;
		const int32_t index;
		const vk::QueueFlags flags;
		int32_t used = 0;
		inline int32_t PickQueueId() {
			return used++;
		}
		inline static vector<QueueFamilyPropertiesExt> GetExtList(const vector <vk::QueueFamilyProperties>& familyProperty) {
			vector<QueueFamilyPropertiesExt> familyMap;/*
			for (int32_t i = 0; i < familyProperty.size(); i++)
				familyMap.push_back(QueueFamilyPropertiesExt{ familyProperty[i].queueCount, i, familyProperty[i].queueFlags });*/
			return familyMap;
		}
	};
	struct QueueManager {
	public:
		vk::Queue graphics;
		vk::Queue presentation;
		vk::Queue transference;

		inline void InitializeHandlers(const vk::PhysicalDevice& physicalDevice,const vk::Device& device) {
			vector<QueueFamilyPropertiesExt> familyMap = QueueFamilyPropertiesExt::GetExtList(physicalDevice.getQueueFamilyProperties());
			int32_t index = -1;
			for (int32_t i = 0; i < familyMap.size(); i++)
			{
				vk::QueueFlags flags = (familyMap[i].flags & vk::QueueFlagBits::eGraphics);
				if (flags == vk::QueueFlagBits::eGraphics) {
					index = i;
				}
			}
			//search unique families
			//	if fail search for double families

		};

		inline void GetQueueCreationInfoList(const vk::PhysicalDevice& physicalDevice,const vk::Device& device, vector<vk::DeviceQueueCreateInfo>& emptyQueueCreationInfoList) {

		};
	};
}