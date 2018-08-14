#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <vector>

#include <vulkan/vulkan.h>

#include "AppInfo.h"
#include "Extensions.h"
#include "LayerProperties.h"

class Instance {
public:
    explicit Instance(VkInstance raw_instance);
    Instance(const AppInfo& info, const Extensions& instance_extensions, const std::vector<const char*>& layers);
    ~Instance();

    Instance(const Instance& other) = delete;
    Instance(Instance&& other) noexcept = default;
    Instance& operator =(const Instance& other) = delete;
    Instance& operator =(Instance&& other) noexcept = default;

    static std::vector<LayerProperties> get_available_instance_layers();
    static bool has_all_instance_layers(const std::vector<const char*>& layers, std::vector<const char*>* conflicts = nullptr);

private:
    VkInstance m_instance;
};

#endif
