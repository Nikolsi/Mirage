#define VULKAN_HPP_NO_EXCEPTIONS

#include <cstdio>
#include <string>

#include <vulkan/vulkan.hpp>

vk::Instance createVulkanInstance(std::string const &appName,
                                  std::string const &engineName)
{
  uint32_t apiVersion;
  vkEnumerateInstanceVersion(&apiVersion);
  std::printf("Vulkan instance version %d.%d.%d\n",
              VK_VERSION_MAJOR(apiVersion), VK_VERSION_MINOR(apiVersion),
              VK_VERSION_PATCH(apiVersion));

  vk::ApplicationInfo applicationInfo(appName.c_str(), 1, engineName.c_str(), 1,
                                      apiVersion);
  vk::InstanceCreateInfo instanceCreateInfo({}, &applicationInfo);
  auto [result, instance] = vk::createInstance(instanceCreateInfo);
  if (result == vk::Result::eSuccess)
  {
    std::printf("great stuff!\n");
  }

  return instance;
}

int main(int argc, char **argv)
{
  auto instance = createVulkanInstance("Mirage Rendering Engine", "Mirage");
  // log the result
  std::printf("Vulkan was initialized\n");

  instance.destroy();
  return 0;
}