#pragma once

#include "defines.h"
#include "vulkan_types.h"
#include "containers/vector.h"

void platform_get_required_extension_names(Vector(const char*)& ext_names_vector);