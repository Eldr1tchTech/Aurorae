#pragma once

// Unsigned int types.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signe int types.
typedef unsigned char i8;
typedef unsigned short i16;
typedef unsigned int i32;
typedef unsigned long long i64;

// Floating point types.
typedef float f32;
typedef double f64;

// Boolean types.
typedef int b32;
typedef char b8;

// Properly define static assertions.
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size.
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes.");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes.");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes.");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes.");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes.");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");

#define TRUE 1
#define FALSE 0

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define APLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
// Linux OS
#define APLATFORM_LINUX 1
#if defined(__ANDROID__)
#define APLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
// Catch anything not caught by the above.
#define APLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
// Posix
#define APLATFORM_POSIX 1
#elif __APPLE__
// Apple platforms
#define APLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS simulator
#define APLATFORM_IOS 1
#define APLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define APLATFORM_IOS 1
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#else
#error "Unknown Apple platform"
#endif
#else
#error "Unkown platform!"
#endif

#ifdef AEXPORT
// Exports
#ifdef _MSC_VER
#define AAPI __declspec(dllexport)
#else
#define AAPI __attribute__((visibility("default")))
#endif
#else
// Imports
#ifdef _MSC_VER
#define AAPI __declspec(dllimport)
#else
#define AAPI
#endif
#endif