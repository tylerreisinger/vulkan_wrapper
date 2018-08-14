#include "DebugMessage.h"


DebugMessage::DebugMessage(VkDebugUtilsMessengerCallbackDataEXT raw_message):
    m_debug_message(raw_message)
{
    m_queue_labels.reserve(m_debug_message.queueLabelCount);
    m_cmd_buffer_labels.reserve(m_debug_message.cmdBufLabelCount);
    m_named_objects.reserve(m_debug_message.objectCount);

    for(uint8_t i = 0; i < m_debug_message.queueLabelCount; ++i) {
        m_queue_labels.push_back(DebugLabel(m_debug_message.pQueueLabels[i]));
    }
    for(uint8_t i = 0; i < m_debug_message.cmdBufLabelCount; ++i) {
        m_cmd_buffer_labels.push_back(DebugLabel(m_debug_message.pCmdBufLabels[i]));
    }
    for(uint8_t i = 0; i < m_debug_message.objectCount; ++i) {
        m_named_objects.push_back(m_debug_message.pObjects[i]);
    }

}
 
DebugNamedObject::DebugNamedObject(VkDebugUtilsObjectNameInfoEXT raw_named_object):
    m_object_name(raw_named_object)
{}
 
DebugLabel::DebugLabel(VkDebugUtilsLabelEXT raw_label):
    m_label(raw_label)
{}
 
