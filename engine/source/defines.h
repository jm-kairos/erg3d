#pragma once

// Unsigned int types
typedef unsigned char CAL_u8;
typedef unsigned short CAL_u16;
typedef unsigned int CAL_u32;
typedef unsigned long long CAL_u64;

// Signed int types
typedef signed char CAL_i8;
typedef signed short CAL_i16;
typedef signed int CAL_i32;
typedef signed long long CAL_i64;

// Floating point types
typedef float CAL_f32;
typedef double CAL_f64;
typedef double CAL_real;

// Boolean types
typedef int CAL_b32;
typedef char CAL_b8;

// Properly define static assertions
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size.
STATIC_ASSERT(sizeof(CAL_u8) == 1, "Expected 'u8' to be 1 byte.");
STATIC_ASSERT(sizeof(CAL_u16) == 2, "Expected 'u16' to be 2 byte.");
STATIC_ASSERT(sizeof(CAL_u32) == 4, "Expected 'u32' to be 4 byte.");
STATIC_ASSERT(sizeof(CAL_u64) == 8, "Expected 'u64' to be 8 byte.");

STATIC_ASSERT(sizeof(CAL_i8) == 1, "Expected 'i8' to be 1 byte.");
STATIC_ASSERT(sizeof(CAL_i16) == 2, "Expected 'i16' to be 2 byte.");
STATIC_ASSERT(sizeof(CAL_i32) == 4, "Expected 'i32' to be 4 byte.");
STATIC_ASSERT(sizeof(CAL_i64) == 8, "Expected 'i64' to be 8 byte.");

STATIC_ASSERT(sizeof(CAL_f32) == 4, "Expected 'f32' to be 4 byte.");
STATIC_ASSERT(sizeof(CAL_f64) == 8, "Expected 'f64' to be 8 byte.");

#define TRUE 1
#define FALSE 0

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define CALPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
#elif defined(__linux__) || defined(__gnu_linus__)
// Linux OS
#define CALPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define CALPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
// Catch uncaught platform
#define CALPLATFORM_POSIX 1
#elif __APPLE__
// Apple platforms
#define CALPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#define CALPLATFORM_IOS 1
#define CALPLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define CALPLATFORM_IOS 1
// iOS devices
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#else
#error "Unknown Apple platform"
#endif
#else
#error "Unknown platform!"
#endif 


// TODO: Explain this further.

#ifdef CALEXPORT
// Exports
#ifdef _MSC_VER
#define CALDERA_API __declspec(dllexport)
#else
#define CALDERA_API __attribute__((visibility("default")))
#endif
#else
// Imports
#ifdef _MSC_VER
#define CALDERA_API __declspec(dllimport)
#else
#define CALDERA_API
#endif
#endif
