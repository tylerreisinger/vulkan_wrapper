#ifndef EXTENSIONS_H_
#define EXTENSIONS_H_

#include <cstring>
#include <iosfwd>
#include <vector>

#include <vulkan/vulkan.h>


class Extension {
public:
    Extension(VkExtensionProperties properties);
    Extension(const char* name);
    ~Extension() = default;

    bool operator ==(const Extension& extension) const { return std::strcmp(m_name, extension.m_name) == 0; }
    bool operator !=(const Extension& extension) const { return !(*this == extension); }

    Extension(const Extension& other) = default;
    Extension(Extension&& other) noexcept = default;
    Extension& operator =(const Extension& other) = default;
    Extension& operator =(Extension&& other) noexcept = default;

    const char* extension_name() const { return m_name; }

private:
    const char* m_name;
};

class Extensions {
public:
    using const_iterator = std::vector<Extension>::const_iterator;
    Extensions() = default;
    Extensions(std::vector<Extension> extensions);
    ~Extensions() = default;

    Extensions(const Extensions& other) = delete;
    Extensions(Extensions&& other) noexcept = default;
    Extensions& operator =(const Extensions& other) = delete;
    Extensions& operator =(Extensions&& other) noexcept = default;

    bool operator ==(const Extensions& rhs) const;
    bool operator !=(const Extensions& rhs) const { return !(*this == rhs); }

    std::size_t size() const { return m_extensions.size(); }
    bool empty() const { return m_extensions.empty(); }

    void push(const char* name);
    void push_all(const std::vector<const char*>& names);

    const_iterator begin() const { return m_extensions.cbegin(); }
    const_iterator end() const { return m_extensions.cend(); }
    const_iterator cbegin() const { return m_extensions.cbegin(); }
    const_iterator cend() const { return m_extensions.cend(); }

    bool contains(const Extension& ex) const;
    Extensions intersection(const Extensions& rhs) const;
    Extensions difference(const Extensions& rhs) const;

    const std::vector<Extension>& as_vector() const { return m_extensions; }

private:
    std::vector<Extension> m_extensions;
};

std::ostream& operator <<(std::ostream& stream, const Extension& extension);
std::ostream& operator <<(std::ostream& stream, const Extensions& extensions);


#endif
