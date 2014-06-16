#---------------------------------------------------------------------------------
# Executable name
#---------------------------------------------------------------------------------
TARGET		:=  $(shell basename $(CURDIR))

#---------------------------------------------------------------------------------
# Source sub-folders
#---------------------------------------------------------------------------------
SUBFOLDERS	:=	activities core display entities managers objects windows

#---------------------------------------------------------------------------------
# Compiler executables
#---------------------------------------------------------------------------------
CC		:=	gcc
CXX		:=	g++

#---------------------------------------------------------------------------------
# Options for code generation
#---------------------------------------------------------------------------------
CFLAGS	:=	-g -Wall
CXXFLAGS:=	$(CFLAGS) -std=c++11 #-MD
LDFLAGS	:=	-g

#---------------------------------------------------------------------------------
# Any extra libraries you wish to link with your project
#---------------------------------------------------------------------------------
LIBS	:=	-lSDL2_ttf -lSDL2_mixer -lSDL2_image -lSDL2

#---------------------------------------------------------------------------------
# Source folders
#--------------------------------------------------------------------------------
BUILD		:=	build
SOURCES		:=	source external $(foreach dir,$(SUBFOLDERS),source/$(dir))
INCLUDES	:=	include external $(foreach dir,$(SUBFOLDERS),include/$(dir))

#---------------------------------------------------------------------------------
# Additional folders for libraries
#---------------------------------------------------------------------------------
LIBDIRS		:= 	

#---------------------------------------------------------------------------------
# Source files
#---------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))

#---------------------------------------------------------------------------------
export OUTPUT	:=	$(CURDIR)/$(TARGET)

export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir))

export CFILES	:=	$(sort $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c))))
export CPPFILES	:=	$(sort $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp))))

SOURCEFILES	:=	$(foreach dir,$(SOURCES),$(wildcard $(dir)/*.c)) \
				$(foreach dir,$(SOURCES),$(wildcard $(dir)/*.cpp))
HEADERFILES	:=	$(foreach dir,$(INCLUDES),$(wildcard $(dir)/*.h)) \
				$(foreach dir,$(INCLUDES),$(wildcard $(dir)/*.hpp))

#---------------------------------------------------------------------------------
# Use CXX for linking C++ projects, CC for standard C
#---------------------------------------------------------------------------------
ifeq ($(strip $(CPPFILES)),)
#---------------------------------------------------------------------------------
	export LD	:=	$(CC)
#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------
	export LD	:=	$(CXX)
#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

export OFILES	:=	$(CPPFILES:.cpp=.o) $(CFILES:.c=.o)

export INCLUDE	:=	$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir))

export LIBPATHS	:=	$(foreach dir,$(LIBDIRS),-L$(CURDIR)/$(dir))

#---------------------------------------------------------------------------------
.PHONY: $(BUILD) clean clear run droid tags install uninstall
#------------------------------------------------------------------------------
$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@make --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

#---------------------------------------------------------------------------------
run:
	@echo running ...
	@./$(TARGET)

#---------------------------------------------------------------------------------
droid:
	@echo making for android ...
	@cd droid && \
	pwd && \
	$(ANDROID_NDK)/ndk-build NDK_DEBUG=1 && \
	ant debug && \
	dropbox start > /dev/null && \
	cp -f bin/$(TARGET)-debug.apk ~/Dropbox/Public/$(TARGET)-debug.apk && \
	cd ..
	@echo done.
	
#---------------------------------------------------------------------------------
tags:
	@echo generating tags file ...
	@ctags $(SOURCEFILES) $(HEADERFILES)
	
#---------------------------------------------------------------------------------
clean:
	@echo clean ...
	@rm -fr $(BUILD) $(TARGET)
	
#---------------------------------------------------------------------------------
clear:
	@echo clear ...
	@rm *~ */*~

#---------------------------------------------------------------------------------
install:
	@cp -u $(TARGET) /usr/bin/$(TARGET)
	@echo installed.

#---------------------------------------------------------------------------------
uninstall:
	@rm -f /usr/bin/$(TARGET)
	@echo uninstalled.

#---------------------------------------------------------------------------------
else

include ../external/make_libs/gmsl

#---------------------------------------------------------------------------------
# Makefile targets
#---------------------------------------------------------------------------------
all: $(OUTPUT)

COUNTER :=	$(words $(notdir $(wildcard *.o)))
T		:=	1

#---------------------------------------------------------------------------------
$(OUTPUT): $(OFILES)
	@echo -ne '\033[2Kbuilt ... $(notdir $@)\n'
	@$(LD) $(LDFLAGS) $(OFILES) $(LIBPATHS) $(LIBS) -o $@

#---------------------------------------------------------------------------------
%.o: %.c
	$(eval COUNTER := $(call plus,$(COUNTER),1))
	@echo -ne '\033[2K [$(call subtract,$(COUNTER),$(words $(notdir $(wildcard *.o))))/$(call subtract,$(call plus,$(words $(CFILES)),$(words $(CPPFILES))),$(call subtract,$(words $(notdir $(wildcard *.o))),$(T)))] $(notdir $<) \r'
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
#---------------------------------------------------------------------------------
%.o: %.cpp
	$(eval COUNTER := $(call plus,$(COUNTER),1))
	@echo -ne '\033[2K [$(call subtract,$(COUNTER),$(words $(notdir $(wildcard *.o))))/$(call subtract,$(call plus,$(words $(CFILES)),$(words $(CPPFILES))),$(call subtract,$(words $(notdir $(wildcard *.o))),$(T)))] $(notdir $<) \r'
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@
	
#-include *.d

#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

