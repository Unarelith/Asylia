LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := native_midi

SDL_PATH 		:= ../SDL2
SDL_MIXER_PATH	:= ../SDL2_mixer

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include \
					$(LOCAL_PATH)/$(SDL_MIXER_PATH)/external \
					$(LOCAL_PATH)/include

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
	$(subst $(LOCAL_PATH)/,, \
	$(wildcard $(LOCAL_PATH)/*.c) \
	$(wildcard $(LOCAL_PATH)/*.cpp))

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_mixer

LOCAL_CPPFLAGS += -std=c++11
LOCAL_LDLIBS := -lGLESv1_CM -llog -landroid

include $(BUILD_SHARED_LIBRARY)
