#include "PhysicalDevice.h"


PhysicalDevice::PhysicalDevice(VkPhysicalDevice vk_physical_device):
    m_physical_device(vk_physical_device) 
{}
 
std::vector<PhysicalDevice> PhysicalDevice::get_available_devices() {
}
 
