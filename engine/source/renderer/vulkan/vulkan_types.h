#pragma once

#include "core\asserts.h"
#include "defines.h"

#include <vulkan/vulkan.h>

#define IBX_VK_EVAL(_result) { IBX_ASSERT(_result == VK_SUCCESS) }

struct VulkanDevice{
    VkPhysicalDevice chosen_gpu_device;
    VkDevice logical_device;
};

struct VulkanContext{
    VkInstance instance;
    VkAllocationCallbacks* allocator;
    VkSurfaceKHR surface;
    VulkanDevice device;
};