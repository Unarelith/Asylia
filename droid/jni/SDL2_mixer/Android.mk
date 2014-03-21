LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := SDL2_mixer

# Enable this if you want to support loading MOD music via modplug
# The library path should be a relative path to this directory.
SUPPORT_MOD_MODPLUG := true
MODPLUG_LIBRARY_PATH := external/libmodplug-0.8.8.4

# Enable this if you want to support loading MOD music via mikmod
# The library path should be a relative path to this directory.
# SUPPORT_MOD_MIKMOD := true
# MIKMOD_LIBRARY_PATH := external/libmikmod-3.1.12

# Enable this if you want to support loading MP3 music via SMPEG
# The library path should be a relative path to this directory.
SUPPORT_MP3_SMPEG := true
SMPEG_LIBRARY_PATH := external/smpeg2-2.0.0

# Enable this if you want to support loading OGG Vorbis music via Tremor
# The library path should be a relative path to this directory.
SUPPORT_OGG := true
OGG_LIBRARY_PATH := external/libogg-1.3.1
VORBIS_LIBRARY_PATH := external/libvorbisidec-1.2.1


LOCAL_C_INCLUDES := $(LOCAL_PATH)
LOCAL_CFLAGS := -DWAV_MUSIC

LOCAL_SRC_FILES := $(notdir $(filter-out %/playmus.c %/playwave.c, $(wildcard $(LOCAL_PATH)/*.c)))

LOCAL_LDLIBS :=
LOCAL_STATIC_LIBRARIES :=
LOCAL_SHARED_LIBRARIES := SDL2

ifeq ($(SUPPORT_MOD_MODPLUG),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(MODPLUG_LIBRARY_PATH)/src $(LOCAL_PATH)/$(MODPLUG_LIBRARY_PATH)/src/libmodplug
    LOCAL_CFLAGS += -DMODPLUG_MUSIC -DHAVE_SETENV -DHAVE_SINF
    LOCAL_SRC_FILES += \
        $(MODPLUG_LIBRARY_PATH)/src/fastmix.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_669.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_abc.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_amf.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_ams.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_dbm.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_dmf.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_dsm.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_far.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_it.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_j2b.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_mdl.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_med.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_mid.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_mod.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_mt2.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_mtm.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_okt.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_pat.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_psm.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_ptm.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_s3m.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_stm.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_ult.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_umx.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_wav.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/load_xm.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/mmcmp.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/modplug.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/snd_dsp.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/snd_flt.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/snd_fx.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/sndfile.cpp \
        $(MODPLUG_LIBRARY_PATH)/src/sndmix.cpp
endif

ifeq ($(SUPPORT_MOD_MIKMOD),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(MIKMOD_LIBRARY_PATH)/include
    LOCAL_CFLAGS += -DMOD_MUSIC
    LOCAL_SHARED_LIBRARIES += mikmod
endif

ifeq ($(SUPPORT_MP3_SMPEG),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(SMPEG_LIBRARY_PATH)
    LOCAL_CFLAGS += -DMP3_MUSIC
	LOCAL_SRC_FILES += \
	$(SMPEG_LIBRARY_PATH)/MPEG.cpp \
	$(SMPEG_LIBRARY_PATH)/MPEGlist.cpp \
	$(SMPEG_LIBRARY_PATH)/MPEGring.cpp \
	$(SMPEG_LIBRARY_PATH)/MPEGstream.cpp \
	$(SMPEG_LIBRARY_PATH)/MPEGsystem.cpp \
	$(SMPEG_LIBRARY_PATH)/plaympeg.c \
	$(SMPEG_LIBRARY_PATH)/smpeg.cpp \
	$(SMPEG_LIBRARY_PATH)/audio/bitwindow.cpp \
	$(SMPEG_LIBRARY_PATH)/audio/filter.cpp \
	$(SMPEG_LIBRARY_PATH)/audio/filter_2.cpp \
	$(SMPEG_LIBRARY_PATH)/audio/hufftable.cpp \
	$(SMPEG_LIBRARY_PATH)/audio/MPEGaudio.cpp \
	$(SMPEG_LIBRARY_PATH)/audio/mpeglayer1.cpp \
	$(SMPEG_LIBRARY_PATH)/audio/mpeglayer2.cpp \
	$(SMPEG_LIBRARY_PATH)/audio/mpeglayer3.cpp \
	$(SMPEG_LIBRARY_PATH)/audio/mpegtable.cpp \
	$(SMPEG_LIBRARY_PATH)/audio/mpegtoraw.cpp \
	$(SMPEG_LIBRARY_PATH)/video/decoders.cpp \
	$(SMPEG_LIBRARY_PATH)/video/floatdct.cpp \
	$(SMPEG_LIBRARY_PATH)/video/gdith.cpp \
	$(SMPEG_LIBRARY_PATH)/video/jrevdct.cpp \
	$(SMPEG_LIBRARY_PATH)/video/mmxflags_asm.S \
	$(SMPEG_LIBRARY_PATH)/video/mmxidct_asm.S \
	$(SMPEG_LIBRARY_PATH)/video/motionvec.cpp \
	$(SMPEG_LIBRARY_PATH)/video/MPEGvideo.cpp \
	$(SMPEG_LIBRARY_PATH)/video/parseblock.cpp \
	$(SMPEG_LIBRARY_PATH)/video/readfile.cpp \
	$(SMPEG_LIBRARY_PATH)/video/util.cpp \
	$(SMPEG_LIBRARY_PATH)/video/video.cpp \
#    LOCAL_SHARED_LIBRARIES += smpeg2
endif

ifeq ($(SUPPORT_OGG),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGG_LIBRARY_PATH)/include $(LOCAL_PATH)/$(VORBIS_LIBRARY_PATH)
    LOCAL_CFLAGS += -DOGG_MUSIC -DOGG_USE_TREMOR
    LOCAL_SRC_FILES += \
        $(VORBIS_LIBRARY_PATH)/mdct.c \
        $(VORBIS_LIBRARY_PATH)/block.c \
        $(VORBIS_LIBRARY_PATH)/window.c \
        $(VORBIS_LIBRARY_PATH)/synthesis.c \
        $(VORBIS_LIBRARY_PATH)/info.c \
        $(VORBIS_LIBRARY_PATH)/floor1.c \
        $(VORBIS_LIBRARY_PATH)/floor0.c \
        $(VORBIS_LIBRARY_PATH)/vorbisfile.c \
        $(VORBIS_LIBRARY_PATH)/res012.c \
        $(VORBIS_LIBRARY_PATH)/mapping0.c \
        $(VORBIS_LIBRARY_PATH)/registry.c \
        $(VORBIS_LIBRARY_PATH)/codebook.c \
        $(VORBIS_LIBRARY_PATH)/sharedbook.c \
        $(OGG_LIBRARY_PATH)/src/framing.c \
        $(OGG_LIBRARY_PATH)/src/bitwise.c
endif

LOCAL_EXPORT_C_INCLUDES += $(LOCAL_C_INCLUDES)

include $(BUILD_SHARED_LIBRARY)
