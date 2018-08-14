#include "InstanceDebugCallback.h"

#include <iostream>

#include "DebugMessage.h"

InstanceDebugCallback::InstanceDebugCallback(Instance& instance, InstanceDebugCallback::CallbackType callback):
    m_callback(std::move(callback))
{}

VkBool32 InstanceDebugCallback::base_debug_callback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, 
        VkDebugUtilsMessageTypeFlagsEXT messageType, 
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, 
        void* pUserData)
{
    InstanceDebugCallback* self = reinterpret_cast<InstanceDebugCallback*>(pUserData);
    auto severity = static_cast<DebugMessageSeverity>(messageSeverity);
    auto type = static_cast<DebugMessageType>(messageType);
    auto message = DebugMessage(*pCallbackData);

    self->m_callback(severity, type, message);

    return VK_FALSE;
}
 
std::ostream& operator <<(std::ostream& stream, DebugMessageSeverity severity) {
    switch(severity) {
        case DebugMessageSeverity::Verbose: stream << "VERBOSE"; break;
        case DebugMessageSeverity::Info: stream << "INFO"; break;
        case DebugMessageSeverity::Warning: stream << "WARNING"; break;
        case DebugMessageSeverity::Error: stream << "Error"; break;
        default: stream << "UNKNOWN"; break;
    }
    return stream;
}
std::ostream& operator <<(std::ostream& stream, DebugMessageType type) {
    switch(type) {
        case DebugMessageType::General: stream << "General"; break;
        case DebugMessageType::Performance: stream << "Performance"; break;
        case DebugMessageType::Validation: stream << "Validation"; break;
        default: stream << "UNKNOWN"; break;
    }
    return stream;
}
 
