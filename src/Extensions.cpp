#include "Extensions.h"

#include <ostream>

Extension::Extension(VkExtensionProperties properties):
    m_name(properties.extensionName)
{}
 
Extension::Extension(const char* name):
    m_name(name)
{} 

Extensions::Extensions(std::vector<Extension> extensions): m_extensions(std::move(extensions)) {}
 
bool Extensions::operator==(const Extensions& rhs) const {
    return m_extensions == rhs.m_extensions;
}
 
bool Extensions::contains(const Extension& ex) const {
    for(const auto& e : m_extensions) {
        if(ex.extension_name() == e.extension_name()) {
            return true;
        }
    }
    return false;
}
 
Extensions Extensions::intersection(const Extensions& rhs) const {
    std::vector<Extension> out;
    for(const auto& ex1 : m_extensions) {
        for(const auto& ex2 : rhs.m_extensions) {
            if(ex1.extension_name() == ex2.extension_name()) {
                out.push_back(ex1);
                break;
            }
        }
    }
    return Extensions(out);
}
 
Extensions Extensions::difference(const Extensions& rhs) const {
    std::vector<Extension> out;

    for(const auto& ex1 : m_extensions) {
        bool found = false;
        for(const auto& ex2 : rhs.m_extensions) {
            if(ex1.extension_name() == ex2.extension_name()) {
                found = true;
                break;
            }
        }
        if(!found) {
            out.push_back(ex1);
        }
    }

    return Extensions(out);
}
 
std::ostream& operator<<(std::ostream& stream, const Extension& extension) {
    stream << extension.extension_name();
    return stream;
}
 
std::ostream& operator<<(std::ostream& stream, const Extensions& extensions) {
    for(const auto& ex : extensions) {
        stream << ex << "\n";
    }
    return stream;
}
 
void Extensions::push(const char* name) {
    m_extensions.push_back(name);
}
 
void Extensions::push_all(const std::vector<const char*>& names) {
    for(auto name : names) {
        m_extensions.push_back(name);
    }
}
 
