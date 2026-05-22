#pragma once

#include <vulkan/vulkan.h>

#include "core\logger.h"

struct VulkanContext{
    VkInstance instance;
    VkAllocationCallbacks* allocator;
};

#define IBX_VULKAN_EVALUATE_ERROR(_result) if(result != VK_SUCCESS) { IBX_LOG_ERROR("vkCreateInstance failed with result: %u", result); return FALSE; } 