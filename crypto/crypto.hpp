#pragma once


#if defined(_WIN32) || defined(__CYGWIN__)
	#ifdef CRYPTO_EXPORTS
		#define CRYPTO_API extern "C" __declspec(dllexport)
	#else
		#define CRYPTO_API extern "C" __declspec(dllimport)
	#endif
#else
	#if defined(__GNUC__) && __GNUC__ >= 4
		#define CRYPTO_API extern "C" __attribute__((visibility("default")))
	#else
		#define CRYPTO_API extern "C"
	#endif
#endif