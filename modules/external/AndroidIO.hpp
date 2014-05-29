#ifndef ANDROID_FOPEN_H
#define ANDROID_FOPEN_H

#ifdef __ANDROID__

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#ifdef __cplusplus
extern "C" {
#endif

void android_setup_asset_manager();
FILE *android_fopen(const char *fname, const char *mode);

#define fopen(name, mode) android_fopen(name, mode)

#ifdef __cplusplus
}
#endif

#endif

#endif
