#ifndef VERSION_H_
#define VERSION_H_

#include <cstdint>
#include <ostream>

class Version {
public:
    Version(int major, int minor, int patch):
        m_version((major << 22) | (minor << 12) | patch) {}
    explicit Version(uint32_t packed_version):
        m_version(packed_version) {}
    ~Version() = default;

    bool operator ==(const Version& rhs) const { return m_version == rhs.m_version; }
    bool operator !=(const Version& rhs) const { return !(*this == rhs); }

    Version(const Version& other) = default;
    Version(Version&& other) noexcept = default;
    Version& operator =(const Version& other) = default;
    Version& operator =(Version&& other) noexcept = default;

    uint16_t major_version() const { return (m_version >> 22); }
    uint16_t minor_version() const { return (m_version >> 12) & 0x3FF; }
    uint16_t patch() const { return m_version & 0xFFF; }

    uint32_t packed_version() const { return m_version; }

private:
    uint32_t m_version;    
};

inline std::ostream& operator <<(std::ostream& stream, const Version& version) {
    stream << version.major_version() << "." << version.minor_version() << "." << version.patch();
    return stream;
}

#endif
