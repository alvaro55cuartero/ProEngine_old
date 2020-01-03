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