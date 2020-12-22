#include <iostream>
#include <vulkan/vulkan.hpp>

static char const *AppName = "Mirage Rendering Engine";
static char const *EngineName = "Mirage";

int main(int argc, char **argv)
{
    // initialize the vk::ApplicationInfo structure
    vk::ApplicationInfo applicationInfo(
        // .pApplicationName =
        AppName,
        // .applicationVersion =
        VK_MAKE_VERSION(1, 0, 0),
        // .pEngineName =
        EngineName,
        // .engineVersion =
        VK_MAKE_VERSION(1, 0, 0),
        // .apiVersion =
        VK_API_VERSION_1_1);
    // initialize the vk::InstanceCreateInfo
    vk::InstanceCreateInfo instanceCreateInfo({}, &applicationInfo);
    // create a UniqueInstance
    vk::UniqueInstance instance = vk::createInstanceUnique(instanceCreateInfo);
    // log the result
    std::cout << "Vulkan was initialized\n";
    return 0;
}