#ifndef DEBUGMESSAGE_H_
#define DEBUGMESSAGE_H_

#include <cstdint>
#include <string_view>
#include <vector>

#include <glm/vec4.hpp>

#include <vulkan/vulkan.h>

class DebugNamedObject {
public:
    DebugNamedObject(VkDebugUtilsObjectNameInfoEXT raw_named_object);
    ~DebugNamedObject() = default;

    DebugNamedObject(const DebugNamedObject& other) = delete;
    DebugNamedObject(DebugNamedObject&& other) noexcept = delete;
    DebugNamedObject& operator =(const DebugNamedObject& other) = delete;
    DebugNamedObject& operator =(DebugNamedObject&& other) noexcept = delete;

    VkObjectType object_type() const { return m_object_name.objectType; }
    uint64_t object_handle() const { return m_object_name.objectHandle; }
    std::string_view object_name() const { return m_object_name.pObjectName; }

    VkDebugUtilsObjectNameInfoEXT vk_object() const { return m_object_name; }

private:
    VkDebugUtilsObjectNameInfoEXT m_object_name;
};

class DebugLabel {
public:
    DebugLabel(VkDebugUtilsLabelEXT raw_label);
    ~DebugLabel() = default;

    DebugLabel(const DebugLabel& other) = default;
    DebugLabel(DebugLabel&& other) noexcept = delete;
    DebugLabel& operator =(const DebugLabel& other) = default;
    DebugLabel& operator =(DebugLabel&& other) noexcept = delete;

    std::string_view label() const { return m_label.pLabelName; }
    glm::vec4 color() const { return glm::vec4(m_label.color[0], m_label.color[1], m_label.color[2], m_label.color[3]); }
    
    VkDebugUtilsLabelEXT vk_object() const { return m_label; }

private:
    VkDebugUtilsLabelEXT m_label;
};

class DebugMessage {
public:
    DebugMessage(VkDebugUtilsMessengerCallbackDataEXT raw_message);
    ~DebugMessage() = default;

    DebugMessage(const DebugMessage& other) = default;
    DebugMessage(DebugMessage&& other) noexcept = delete;
    DebugMessage& operator =(const DebugMessage& other) = default;
    DebugMessage& operator =(DebugMessage&& other) noexcept = delete;

    std::string_view id_string() const { return m_debug_message.pMessageIdName; }
    int32_t id_number() const { return m_debug_message.messageIdNumber; }
    std::string_view message() const { return m_debug_message.pMessage; }

    const std::vector<DebugLabel>& queue_labels() const { return m_queue_labels; }
    const std::vector<DebugLabel>& cmd_buffer_labels() const { return m_cmd_buffer_labels; }
    const std::vector<DebugNamedObject>& named_objects() const { return m_named_objects; }

    VkDebugUtilsMessengerCallbackDataEXT vk_object() const { return m_debug_message; }

private:
    VkDebugUtilsMessengerCallbackDataEXT m_debug_message;
    std::vector<DebugLabel> m_queue_labels;
    std::vector<DebugLabel> m_cmd_buffer_labels;
    std::vector<DebugNamedObject> m_named_objects;
};

#endif
