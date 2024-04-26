#ifndef SANDBOX_EXPORT_H
#define SANDBOX_EXPORT_H
#if COMPILER_ID == 1

#if defined(MAKE_SANDBOX) 

#ifdef __APPLE__
#  define SANDBOX_API __attribute__((visibility("default")))
#else
#  define SANDBOX_API __declspec(dllexport)
#  define SANDBOX_FUNC_API extern "C" __declspec(dllexport)
#endif // __APPLE__
#else

#ifdef __APPLE__
#  define SANDBOX_API __attribute__((visibility("default")))
#else
#  define SANDBOX_API __declspec(dllimport)
#endif // __APPLE__

#endif// MAKE_SECTOR
#else

#  define SANDBOX_API 
#  define SANDBOX_API

#endif // COMPILER_ID
#endif // SANDBOX_EXPORT_H