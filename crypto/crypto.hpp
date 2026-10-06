#pragma once

#ifdef CRYPTO_EXPORTS
#define COMPRESS_API extern "C" __declspec(dllexport)
#else
#define COMPRESS_API extern "C" __declspec(dllimport)
#endif