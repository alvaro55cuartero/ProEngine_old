#pragma once

#ifdef PRO_PLATFORM_WINDOWS
	#ifdef PRO_BUILD_DLL
		#define PRO_API __declspec(dllexport)
	#else 
		#define PRO_API __declspec(dllimport)
	#endif
#else 
	#error ProEngine only supports Windows
#endif

#ifdef PRO_ENABLE_ASSERTS
	#define PRO_ASERT(x, ...) { if(!(x)) { PRO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define PRO_CORE_ASERT(x, ...) { if(!(x)) { PRO_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define PRO_ASERT(x, ...)
	#define PRO_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)