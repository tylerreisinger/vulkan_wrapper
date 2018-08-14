#include "TriangleDemo.h"

#include <iostream>

#include "AppInfo.h"
#include "Extensions.h"
#include "Version.h"


TriangleDemo::TriangleDemo() {
 
}
 
TriangleDemo::~TriangleDemo() {
 
}
 
void TriangleDemo::run() {
    initialize();
}

void TriangleDemo::initialize() {
    create_instance();
}
 
void TriangleDemo::create_instance() {
    AppInfo app_info = AppInfo()
        .with_app_name("Triangle Demo")
        .with_engine_name("None")
        .with_vulkan_version(Version(1, 0, 0));

    Extensions extension_list = {{
        VK_EXT_DEBUG_UTILS_EXTENSION_NAME,
    }};
    std::vector<const char*> layers = 
    {
        "VK_LAYER_LUNARG_standard_validation",
    };

    std::vector<const char*> conflicts;
    if(!Instance::has_all_instance_layers(layers, &conflicts)) {
        std::cout << "Unable to find requested validation layers: \n";
        for(auto conflict : conflicts) {
            std::cout << "\t" << conflict << "\n";
        }
        layers.clear();
    }

    m_instance = std::make_unique<Instance>(app_info, extension_list, layers);
}
 
