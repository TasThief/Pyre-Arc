#pragma once
#include "Requirements.hpp"

namespace Servo {
	//Each queue family type has a queuefamilyproperty ext
	struct QueueFamilyPropertiesExt {
		//How many queues this device has
		const uint32_t count;

		//The index of this queue
		const int32_t index;

		//The queue flag
		const vk::QueueFlags flags;

		//How many queues where used
		uint32_t used = 0;

		//Draws a queue from this family. queueId is a integer with the queue's index, returns if managed to draw a open queue
		inline bool PickQueueId(int32_t& queueId) {
			//If the family has a open queue
			bool result = false;

			///If it has open queues
			if (used < count) {
				///return its 
				queueId = used++;

				///set the draw as sucessful
				result = true;
			}
			return result;
		}

		//Reset the used queues back to 0, so the draw system is able to draw repeated queues
		inline void ResetQueueDrawId() {
			used = 0;
		}

		//Builds a vector of family properties ext for each type of family
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