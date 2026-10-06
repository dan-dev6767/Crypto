#pragma once


#if defined(_WIN32) || defined(__CYGWIN__)
	#ifdef CRYPTO_EXPORTS
		#define CRYPTO_API __declspec(dllexport)
	#else
		#define CRYPTO_API __declspec(dllimport)
	#endif
#else
	#if defined(__GNUC__) && __GNUC__ >= 4
		#define CRYPTO_API __attribute__((visibility("default")))
	#else
		#define CRYPTO_API
	#endif
#endif

extern "C" CRYPTO_API void LazyEncrypt( void );
extern "C" CRYPTO_API void LazyDecrypt( void );