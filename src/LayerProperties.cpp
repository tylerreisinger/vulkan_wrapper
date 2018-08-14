#include "LayerProperties.h"

#include <ostream>

LayerProperties::LayerProperties(VkLayerProperties raw_properties):
    m_properties(raw_properties)
{}
 
std::ostream& operator<<(std::ostream& stream, const LayerProperties& properties) {
    stream << properties.name() << ": " << properties.description() << ". Revision " << properties.impl_version() << " for vulkan " << properties.spec_version() << ".";
    return stream;
}
 
bool LayerProperties::operator==(const LayerProperties& rhs) const {
    return name() == rhs.name() && spec_version() == rhs.spec_version() && impl_version() == rhs.impl_version();
}
 
