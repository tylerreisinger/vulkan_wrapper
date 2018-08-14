#include <iostream>

void vk_check_failure(const char* file, int line, const char* invocation) {
    std::cerr << "Vulkan call failed at " << file <<":" << line
        << ": " << invocation << std::endl;
    std::exit(-1);
}
