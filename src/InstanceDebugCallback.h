#ifndef INSTANCEDEBUGCALLBACK_H_
#define INSTANCEDEBUGCALLBACK_H_

#include <cstdint>
#include <functional>
#include <iosfwd>

#include <vulkan/vulkan.h>

#include "Instance.h"

class DebugMessage;

enum class DebugMessageSeverity : uint32_t {
    Verbose = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT,
    Info = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT,
    Warning = VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT,
    Error = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
};

enum class DebugMessageType: uint32_t {
    General = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT,
    Validation = VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT,
    Performance = VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
};

class InstanceDebugCallback {
public:
    using CallbackType = std::function<void (DebugMessageSeverity, DebugMessageType, const DebugMessage&)>;

    InstanceDebugCallback(Instance& instance, CallbackType callback);
    ~InstanceDebugCallback() = default;

    InstanceDebugCallback(const InstanceDebugCallback& other) = delete;
    InstanceDebugCallback(InstanceDebugCallback&& other) noexcept = delete;
    InstanceDebugCallback& operator =(const InstanceDebugCallback& other) = delete;
    InstanceDebugCallback& operator =(InstanceDebugCallback&& other) noexcept = delete;


private:
    CallbackType m_callback;

    static VKAPI_ATTR VkBool32 VKAPI_CALL base_debug_callback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData);

};

std::ostream& operator <<(std::ostream& stream, DebugMessageSeverity severity);
std::ostream& operator <<(std::ostream& stream, DebugMessageType type);

inline bool operator >=(DebugMessageSeverity lhs, DebugMessageSeverity rhs) 
    { return static_cast<uint32_t>(lhs) >= static_cast<uint32_t>(rhs); }
inline bool operator >(DebugMessageSeverity lhs, DebugMessageSeverity rhs)
    { return static_cast<uint32_t>(lhs) > static_cast<uint32_t>(rhs); }
inline bool operator <=(DebugMessageSeverity lhs, DebugMessageSeverity rhs)
    { return static_cast<uint32_t>(lhs) <= static_cast<uint32_t>(rhs); }
inline bool operator <(DebugMessageSeverity lhs, DebugMessageSeverity rhs)
    { return static_cast<uint32_t>(lhs) < static_cast<uint32_t>(rhs); }

#endif
