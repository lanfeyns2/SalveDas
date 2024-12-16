#ifdef SD_WINDOWS
	#ifdef SD_BUILD_DLL
		#define SALVE_DAS_API __declspec(dllexport)
	#else
		#define SALVE_DAS_API __declspec(dllimport)
	#endif // SD_BUIL_DLL
#else
#error SALVE DAS ONLY SUPPORTS WINDOWS
#endif // SD_WINDOWS
