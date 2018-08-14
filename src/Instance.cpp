#include "Instance.h"

#include "debug.h"

Instance::Instance(VkInstance raw_instance):
    m_instance(raw_instance)
{}
 
Instance::~Instance() {
    if(m_instance != VK_NULL_HANDLE) {
        vkDestroyInstance(m_instance, nullptr);
    }
}
 
Instance::Instance(const AppInfo& info, const Extensions& instance_extensions, const std::vector<const char*>& layers) {
    VkInstanceCreateInfo create_info;
    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.pNext = nullptr;
    create_info.flags = 0;
    create_info.pApplicationInfo = &info.raw_value();
    create_info.enabledExtensionCount = instance_extensions.size();
    create_info.ppEnabledExtensionNames = reinterpret_cast<const char* const*>(instance_extensions.as_vector().data());
    create_info.enabledLayerCount = layers.size();
    create_info.ppEnabledLayerNames = layers.data();

    VK_CHECK(vkCreateInstance(&create_info, nullptr, &m_instance));
}
 
std::vector<LayerProperties> Instance::get_available_instance_layers() {
    uint32_t layer_count;
    vkEnumerateInstanceLayerProperties(&layer_count, nullptr);

    std::vector<LayerProperties> layers(layer_count);
    vkEnumerateInstanceLayerProperties(&layer_count, reinterpret_cast<VkLayerProperties*>(layers.data()));

    return layers;
}
bool Instance::has_all_instance_layers(const std::vector<const char*>& layers, std::vector<const char*>* conflicts) {
    bool success = true;
    auto available_layers = get_available_instance_layers();
    for(const auto& test_layer : layers) {
        bool found = false;
        for(const auto& available_layer : available_layers) {
            if(std::strcmp(test_layer, available_layer.name()) == 0) {
                found = true;
                break;
            }
        }
        if(!found) {
            success = false;
            if(conflicts != nullptr) {
                conflicts->push_back(test_layer);
            } else {
                return false;
            }
        }
    }
    return success;
}
 
