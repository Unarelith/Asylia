#ifdef __ANDROID__

#include <stdio.h>
#include <errno.h>
#include <jni.h>
#include "AndroidIO.hpp"
#include "Config.hpp"
#include "Debug.hpp"

static int android_read(void *cookie, char *buf, int size) {
	return AAsset_read((AAsset*)cookie, buf, size);
}

static int android_write(void *cookie, const char *buf, int size) {
	return EACCES; // Can't provide write access to the apk
}

static fpos_t android_seek(void *cookie, fpos_t offset, int whence) {
	return AAsset_seek((AAsset*)cookie, offset, whence);
}

static int android_close(void *cookie) {
	AAsset_close((AAsset*)cookie);
	return 0;
}

AAssetManager *android_asset_manager;
extern "C" JNIEXPORT void JNICALL Java_com_quent42340_asylia_Asylia_load(JNIEnv *env, jobject obj, jobject assetManager) {
	android_asset_manager = AAssetManager_fromJava(env, assetManager);
	if(!android_asset_manager) {
		error("Unable to load asset manager");
	}
}

FILE *android_fopen(const char *fname, const char *mode) {
	if(mode[0] == 'w') return NULL;
	
	AAsset *asset = AAssetManager_open(android_asset_manager, fname, 0);
	if(!asset) return NULL;
	
	return funopen(asset, android_read, android_write, android_seek, android_close);
}

#endif
