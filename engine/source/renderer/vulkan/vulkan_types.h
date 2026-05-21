#pragma once

#include <vulkan/vulkan.h>

#include "renderer/renderer_types.h"

#include "core\logger.h"

struct VulkanContext{
    VkInstance instance;
    VkAllocationCallbacks* allocator;
};
#define PRNT(a,b) \
  printf("value 1 = %d\n", a); \
  printf("value 2 = %d\n", b) ;

#define CAL_VK_ERROR(_result) if(result != VK_SUCCESS) { CAL_LOG_ERROR("vkCreateInstance failed with result: %u", result); return FALSE; } 