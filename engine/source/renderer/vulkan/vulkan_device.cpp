#include "vulkan_device.h"

#include "core/logger.h"
#include "containers/vector.h"

b8 vulkan_check_physical_device_suitability(const VkPhysicalDevice device);

b8 vulkan_device_create(VulkanContext* context){

    u32 physical_devices_count = 0;
    IBX_VK_EVAL(vkEnumeratePhysicalDevices(context->instance, &physical_devices_count, 0));

    Vector(VkPhysicalDevice) physical_devices = {};
    physical_devices.reserve(physical_devices_count);
    IBX_VK_EVAL(vkEnumeratePhysicalDevices(context->instance, &physical_devices_count, physical_devices.data()));

    IBX_LOG_INFO("Searching for a suitable Physical Device:");
    b8 found = FALSE;
    size_t present_physical_devices_count = physical_devices.size();
    for (size_t i = 0; i < present_physical_devices_count; ++i)
    {
        const VkPhysicalDevice device = physical_devices[i];
        if (vulkan_check_physical_device_suitability(device))
        {
            IBX_LOG_INFO("Found.");
            found = TRUE;
            context->device.chosen_gpu_device = device;
            break;
        }
    }

    if (!found)
    {
        IBX_LOG_FATAL("No suitable Physical devices found. Aborting Vulkan initialization.");
        return FALSE;
    }

    return TRUE;
}

void vulkan_device_release(VulkanContext* context){
    vkDestroyDevice(context->device.logical_device, context->allocator);
}


b8 vulkan_check_physical_device_suitability(const VkPhysicalDevice device){
    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties(device, &properties);
    VkPhysicalDeviceFeatures features;
    vkGetPhysicalDeviceFeatures(device, &features);

    b8 desired_properties = TRUE;
    b8 desired_features = TRUE;

    return(desired_properties && desired_features);
}
