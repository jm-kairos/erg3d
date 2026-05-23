#pragma once

#include "core\asserts.h"
#include "defines.h"

#include <vulkan/vulkan.h>

struct VulkanContext{
    VkInstance instance;
    VkAllocationCallbacks* allocator;
};

#define IBX_VK_EVAL(_result) { IBX_ASSERT(_result) }