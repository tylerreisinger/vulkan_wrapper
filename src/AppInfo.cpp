#include "AppInfo.h"

AppInfo::AppInfo()
{
    m_app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    m_app_info.pNext = nullptr; 
    m_app_info.pApplicationName = m_app_name.c_str();
    m_app_info.pEngineName = m_engine_name.c_str();
    m_app_info.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
    m_app_info.engineVersion = VK_MAKE_VERSION(0, 0, 1);
    m_app_info.apiVersion = VK_MAKE_VERSION(1, 0, 0);
}
 
AppInfo& AppInfo::with_app_name(std::string name) {
    m_app_name = std::move(name);
    m_app_info.pApplicationName = m_app_name.c_str();
    return *this;
}
 
AppInfo& AppInfo::with_engine_name(std::string name) {
    m_engine_name = std::move(name);
    m_app_info.pEngineName = m_engine_name.c_str();
    return *this;
}
 
AppInfo& AppInfo::with_app_version(Version version) {
    m_app_info.applicationVersion = version.packed_version();
    return *this;
}
 
AppInfo& AppInfo::with_engine_version(Version version) {
    m_app_info.engineVersion = version.packed_version();
    return *this;
}

AppInfo& AppInfo::with_vulkan_version(Version version) {
    m_app_info.apiVersion = version.packed_version();
    return *this;
}
