#ifndef LAYERPROPERTIES_H_
#define LAYERPROPERTIES_H_

#include <iosfwd>
#include <vector>

#include <vulkan/vulkan.h>

#include "Version.h"

class LayerProperties {
public:
    LayerProperties() = default;
    LayerProperties(VkLayerProperties raw_properties);
    ~LayerProperties() = default;

    bool operator ==(const LayerProperties& rhs) const;
    bool operator !=(const LayerProperties& rhs) const { return !(*this == rhs); }

    LayerProperties(const LayerProperties& other) = default;
    LayerProperties(LayerProperties&& other) noexcept = default;
    LayerProperties& operator =(const LayerProperties& other) = default;
    LayerProperties& operator =(LayerProperties&& other) noexcept = default;

    const char* name() const { return m_properties.layerName; }
    const char* description() const { return m_properties.description; }
    Version spec_version() const { return Version(m_properties.specVersion); }
    uint32_t impl_version() const { return m_properties.implementationVersion; }

    const VkLayerProperties& raw_properties() const { return m_properties; }

private:
    VkLayerProperties m_properties = {};
};

std::ostream& operator <<(std::ostream& stream, const LayerProperties& properties);

#endif
