#ifndef PHYSICALDEVICE_H_
#define PHYSICALDEVICE_H_

#include <vector>

#include <vulkan/vulkan.h>

class PhysicalDevice {
public:
    explicit PhysicalDevice(VkPhysicalDevice vk_physical_device);
    ~PhysicalDevice() = default;

    PhysicalDevice(const PhysicalDevice& other) = delete;
    PhysicalDevice(PhysicalDevice&& other) noexcept = default;
    PhysicalDevice& operator =(const PhysicalDevice& other) = delete;
    PhysicalDevice& operator =(PhysicalDevice&& other) noexcept = default;

    static std::vector<PhysicalDevice> get_available_devices();

private:
    VkPhysicalDevice m_physical_device;
};

#endif
