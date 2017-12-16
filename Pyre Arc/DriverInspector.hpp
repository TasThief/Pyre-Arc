#include "Requirements.hpp"
namespace Engine {
	class DriverInspector {
	public:
		int grade = 0;
		bool avaliability;
		vk::PhysicalDevice& device;

		inline DriverInspector(vk::PhysicalDevice & deviceRef) : device(deviceRef) {
			
		};

		inline bool CheckAvailability() {
			return true;
		};

		inline void Grade() {

		};
		inline void GetPresentationQueue() {

		};
	};
}