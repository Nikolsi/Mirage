#include <cstdio>
#include <vector>

#include <vku/vku.hpp> // Vulkan learning module + <vulkan/vulkan.hpp>

#include <mirage/context.hpp>      // Mirage Rendering context interface
#include <mirage_glfw/context.hpp> // GLFW Rendering context -> Mirage Rendering context.

#include <GLFW/glfw3.h>

std::shared_ptr<GLFWwindow> createApplicationGLFW()
{
    // do not create OpenGL(or ES) context
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    return std::shared_ptr<GLFWwindow>(
        // window constructor
        glfwCreateWindow(1280, 720, "Vulkan + GLFW", NULL, NULL),
        // window destructor
        glfwDestroyWindow);
}

int main(int argc, char **argv)
{
    // setup GLFW
    if (!glfwInit())
    {
        printf("Error: %s\n", "Initialization failed");
        return 1;
    }

    // setup Vulkan
    if (!glfwVulkanSupported())
    {
        printf("Error: %s\n", "GLFW Vulkan Not Supported");
        return 1;
    }

    // window
    auto window = createApplicationGLFW();

    // rendering context
    std::shared_ptr<Mirage::IContext> context = Mirage::GLFW::Context::create(window);

    // // rendering engine
    // auto engine = Mirage::Engine(context);

    glfwSetKeyCallback(window.get(), [](GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    });

    // ---- vulkan ----
    // vk::Application
    vk::ApplicationInfo applicationInfo("Mirage Rendering Engine", 1, "Mirage", 1, VK_API_VERSION_1_2);
    // vk::InstanceCreateInfo
    vk::InstanceCreateInfo instanceCreateInfo({}, &applicationInfo);

    // see the native one: https://github.com/SaschaWillems/Vulkan/blob/master/base/vulkanexamplebase.cpp
    uint32_t glfwExtensionCount = 0;
    const char **glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    instanceCreateInfo.enabledExtensionCount = glfwExtensionCount;
    instanceCreateInfo.ppEnabledExtensionNames = glfwExtensions;
    instanceCreateInfo.enabledLayerCount = 0;

    // vk::Instance
    vk::Instance instance;
    // vk::Surface
    vk::SurfaceKHR surface;
    {
        // [vk::Result, vk::Instance]
        auto [result, _instance] = vk::createInstance(instanceCreateInfo);
        VkSurfaceKHR _surface;
        vk::Result surfaceResult = vk::Result(glfwCreateWindowSurface(_instance, window.get(), nullptr, &_surface));
        if (surfaceResult != vk::Result::eSuccess)
        {
            std::printf("Failed to create window surface!\n");
            return 1;
        }
        instance = _instance;
        surface = _surface;
        std::printf("Surface initialized\n");
    }

    // vk::PhysicalDevice
    vk::PhysicalDevice physicalDevice;
    {
        auto [result, devices] = instance.enumeratePhysicalDevices();
        if (result != vk::Result::eSuccess)
        {
            std::printf("Failed to enumerate physical devices, error: %d!\n", result);
        }
        physicalDevice = devices.front();
        std::printf("Device was found\n");
    }

    // // vk::QueueFamily
    // auto queueFamilyProperties = physicalDevice.getQueueFamilyProperties();

    // event loop
    while (!glfwWindowShouldClose(window.get()))
    {
        glfwPollEvents();
    }

    // destroy rendering engine
    // engine.dispose();

    // destroy window
    window.reset(); // deletes managed GLFW Window object

    // destroy vulkan
    instance.destroy(surface); // destroy surface
    instance.destroy();        // destroy vulkan instance, vk::PhysicalDevice is destroyed automatically

    // destroy GLFW
    glfwTerminate();

    return 0;
}
