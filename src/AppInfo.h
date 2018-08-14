#ifndef APPINFO_H_
#define APPINFO_H_

#include <vulkan/vulkan.h>

#include <string>

#include "Version.h"

class AppInfo {
public:
    AppInfo();
    ~AppInfo() = default;

    AppInfo(const AppInfo& other) = default;
    AppInfo(AppInfo&& other) noexcept = default;
    AppInfo& operator =(const AppInfo& other) = default;
    AppInfo& operator =(AppInfo&& other) noexcept = default;

    AppInfo& with_app_name(std::string name);
    AppInfo& with_engine_name(std::string name);
    AppInfo& with_app_version(Version version);
    AppInfo& with_engine_version(Version version);
    AppInfo& with_vulkan_version(Version version);

    const VkApplicationInfo& raw_value() const { return m_app_info; }

private:
    VkApplicationInfo m_app_info;
    std::string m_app_name;
    std::string m_engine_name;
};

#endif
