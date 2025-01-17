# Copyright 1994-2021 The MathWorks, Inc.
#
# File    : ert_lcc64.tmf   
#
# Abstract:
#       Template makefile for building a PC-based stand-alone embedded real-time 
#       version of Simulink model using generated C code and 
#			LCC compiler Version 2.4
#
#       This makefile attempts to conform to the guidelines specified in the
#       IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make (gmake) which is located in matlabroot/bin/win64.
#
#       Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#         OPT_OPTS       - Optimization options. Default is none. To enable 
#                          debugging specify as OPT_OPTS=-g4. 
#         OPTS           - User specific compile options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths 
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#                          (For Lcc, have a '/'as file separator before the 
#                          file name instead of a '\' . 
#                          i.e.,  d:\work\proj1/myfile.c - reqd for 'gmake')
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see ert.tlc

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = "%MATLAB%\bin\win64\gmake"
SHELL           = cmd
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = any

# Opt in to simplified format by specifying compatible Toolchain
TOOLCHAIN_NAME = "LCC-win64 v2.4.1 | gmake (64-bit Windows)"

MAKEFILE_FILESEP = /

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link. 
#  NUMST               - Number of sample times
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  INTEGER_CODE        - yes (1) or no (0): Is generated code purely integer
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done,
#                        if 0, the generated code runs indefinitely
#  MULTI_INSTANCE_CODE - Is the generated code multi instantiable (1/0)?
#  SHRLIBTARGET        - Is this build intended for generation of a shared library instead 
#                        of executable (1/0)?
#  MAKEFILEBUILDER_TGT - Is this build performed by the MakefileBuilder class
#                        e.g. to create a PIL executable?
#  STANDALONE_SUPPRESS_EXE - Build the standalone target but only create object code modules 
#                            and do not build an executable

MODEL                = Square_HFI
MODULES              = Square_HFI.c Square_HFI_capi.c Square_HFI_data.c Square_HFI_tgtconn.c rtGetInf.c rtGetNaN.c rt_nonfinite.c rt_logging_mmi_simtarget.c rtw_modelmap_utils_simtarget.c raccel_main.c raccel_sup.c raccel_mat.c simulink_solver_api.c raccel_utils.c common_utils.c ext_svr.c updown.c ext_work.c rtiostream_interface.c rtiostream_tcpip.c rtiostream_utils.c
PRODUCT              = Square_HFI.exe
MAKEFILE             = Square_HFI.mk
MATLAB_ROOT          = D:/Program Files/MATLAB/R2022b
ALT_MATLAB_ROOT      = D:/Program Files/MATLAB/R2022b
START_DIR            = E:/STM32SSC/STM32/STM32SSC_Engine/Code/Test_Code/4_PMSM/1_FOC/5_HFI/Square_HFI
S_FUNCTIONS_LIB      = $(MATLAB_ROOT)\sys\lcc64\lcc64\lib64\wsock32.lib
NUMST                = 3
NCSTATES             = 32
BUILDARGS            = MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  RSIM_SOLVER_SELECTION=2 PCMATLABROOT="D:\\Program Files\\MATLAB\\R2022b" EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 TMW_EXTMODE_TESTING=0 RSIM_PARAMETER_LOADING=1 OPTS="-DTGTCONN -DIS_SIM_TARGET -DNRT -DRSIM_PARAMETER_LOADING -DRSIM_WITH_SL_SOLVER -DENABLE_SLEXEC_SSBRIDGE=1 -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DON_TARGET_WAIT_FOR_START=0 -DTID01EQ=1"
MULTITASKING         = 0
INTEGER_CODE         = 0
MAT_FILE             = 1
ALLOCATIONFCN        = 0
ONESTEPFCN           = 0
TERMFCN              = 1
MULTI_INSTANCE_CODE  = 0
CLASSIC_INTERFACE    = 1
MODELREFS            = 
SHRLIBTARGET         = 0
MAKEFILEBUILDER_TGT  = 0
ENABLE_SLEXEC_SSBRIDGE  = 1
STANDALONE_SUPPRESS_EXE = 0
OPTIMIZATION_FLAGS      = 
ADDITIONAL_LDFLAGS      = 
DEFINES_CUSTOM          = -DEXT_MODE -DIS_RAPID_ACCEL 
DEFINES_OTHER           = -DHAVESTDIO
COMPILE_FLAGS_OTHER     = -mcmodel=medium
SYSTEM_LIBS             = -L"D:\Program Files\MATLAB\R2022b\extern\lib\win64\microsoft" libmwipp.lib libut.lib libmx.lib libmex.lib libmat.lib libmwmathutil.lib libmwslsa_sim.lib libmwslexec_simbridge.lib libmwsl_fileio.lib libmwsigstream.lib libmwsl_AsyncioQueue.lib libmwsl_services.lib libmwsdi_raccel.lib libmwi18n.lib libmwcoder_target_services.lib libmwcoder_ParamTuningTgtAppSvc.lib libmwslpointerutil.lib libmwsl_simtarget_instrumentation.lib libfixedpoint.lib libmwslexec_simlog.lib libmwstringutil.lib
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = Square_HFI_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ../../..
FMT_RELATIVE_PATH_TO_ANCHOR   = $(subst /,\,$(RELATIVE_PATH_TO_ANCHOR))
# NONE: standalone, SIM: modelref sim, RTW: modelref coder target
MODELREF_TARGET_TYPE       = NONE
MODELREF_SFCN_SUFFIX       = _msf


#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif

#--------------------------- Tool Specifications -------------------------------

LCC = $(MATLAB_ROOT)\sys\lcc64\lcc64
include $(MATLAB_ROOT)\rtw\c\tools\lcc64tools.mak

CMD_FILE             = $(MODEL).rsp

#------------------------------ Include Path -----------------------------------

# Additional includes 

ADD_INCLUDES = \
	-I$(START_DIR) \
	-I$(START_DIR)/slprj/raccel/Square_HFI \
	-I$(MATLAB_ROOT)/rtw/c/src/rapid \
	-I$(MATLAB_ROOT)/rtw/c/raccel \
	-I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common \
	-I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip \
	-I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils \


# see COMPILER_INCLUDES from lcctool.mak

INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(ADD_INCLUDES) \
           $(COMPILER_INCLUDES) $(USER_INCLUDES)

#-------------------------------- C Flags --------------------------------------

# Optimization Options
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
OPTS =

# Compiler options, etc:
ifneq ($(OPTIMIZATION_FLAGS),)
CC_OPTS = $(OPTS) $(ANSI_OPTS) $(COMPILE_FLAGS_OTHER) $(OPTIMIZATION_FLAGS)
else
CC_OPTS = $(OPTS) $(ANSI_OPTS) $(COMPILE_FLAGS_OTHER) $(OPT_OPTS) 
endif

# Defines
CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DNUMST=$(NUMST) -DNCSTATES=$(NCSTATES) \
		  -DMAT_FILE=$(MAT_FILE) -DINTEGER_CODE=$(INTEGER_CODE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DHAVESTDIO -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
		  -DCLASSIC_INTERFACE=$(CLASSIC_INTERFACE) \
		  -DALLOCATIONFCN=$(ALLOCATIONFCN)

ifeq ($(MODELREF_TARGET_TYPE),SIM)
ifneq ($(ENABLE_SLEXEC_SSBRIDGE), 0)
CPP_REQ_DEFINES += -DENABLE_SLEXEC_SSBRIDGE=$(ENABLE_SLEXEC_SSBRIDGE)
endif
else
CPP_REQ_DEFINES += -DMT=$(MULTITASKING)
endif

CPP_REQ_DEFINES += -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=$(MODEL_HAS_DYNAMICALLY_LOADED_SFCNS)

DEFINES = $(DEFINES_CUSTOM) $(CPP_REQ_DEFINES) $(DEFINES_OTHER)

CFLAGS = $(DEFAULT_CFLAGS) $(CC_OPTS) $(DEFINES) $(INCLUDES) -w -noregistrylookup

# Additional flags required for SIM target
CFLAGS += -dll -Zp8 -noregistrylookup -DLCC_WIN64

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
LDFLAGS = -s -L$(LIB)
else
LDFLAGS = -L$(LIB)
endif

#-------------------------- Additional Libraries ------------------------------

LIBS =


LIBS +=  $(S_FUNCTIONS_LIB)

#----------------------------- Source Files ------------------------------------
ADD_SRCS =

SRCS = $(ADD_SRCS) $(MODULES)

USER_SRCS =

USER_OBJS       = $(USER_SRCS:.c=.obj)
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

OBJS      = $(SRCS:.c=.obj) $(USER_OBJS)

DEF_FILE = $(MODEL).def

#--------------------------------- Rules ---------------------------------------
BIN_SETTING        = $(LD) $(LDFLAGS) $(ADDITIONAL_LDFLAGS) -o $(PRODUCT)
ifeq ($(MODELREF_TARGET_TYPE),NONE)
  ifeq ($(SHRLIBTARGET),1)
    BIN_SETTING        = $(LD) $(LDFLAGS) $(ADDITIONAL_LDFLAGS) -dll -entry LibMain -o $(PRODUCT)
    $(PRODUCT) : $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) @$(CMD_FILE) $(LOCAL_USER_OBJS) @$(MODELREF_LINK_RSPFILE) $(LIBS) $(SYSTEM_LIBS) $(MODEL).def
	@cmd /C "echo ### Created dynamically linked library: $@"
  else
    ifeq ($(MAKEFILEBUILDER_TGT),1)
      PREBUILT_OBJS       = $(MODULES:.c=.obj)
      $(PRODUCT) : $(PREBUILT_OBJS) $(OBJS) $(MODELLIB) $(LIBS) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) $(PREBUILT_OBJS) @$(CMD_FILE) $(LOCAL_USER_OBJS) $(MODELLIB) @$(MODELREF_LINK_RSPFILE) $(LIBS)
	@cmd /C "echo ### Created executable: $@"
    else
      ifeq ($(STANDALONE_SUPPRESS_EXE), 1)
        .PHONY: $(PRODUCT)
        $(PRODUCT) : $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Created object modules $@"
      else
        $(PRODUCT) : $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) @$(CMD_FILE) $(LOCAL_USER_OBJS) @$(MODELREF_LINK_RSPFILE) $(LIBS) $(SYSTEM_LIBS)
	@cmd /C "echo ### Created executable: $@"
      endif
    endif
  endif
else
 ifeq ($(MODELREF_TARGET_TYPE),SIM)  
  $(PRODUCT) : $(OBJS) $(LIBS)
	@if exist $(MODELLIB) del "$(MODELLIB)"
	$(LIBCMD) /out:$(MODELLIB) @$(CMD_FILE) $(LOCAL_USER_OBJS)
	@cmd /C "echo ### Created $(MODELLIB)"  
 else
  $(PRODUCT) : $(OBJS)
	@if exist $(MODELLIB) del "$(MODELLIB)"
	$(LIBCMD) /out:$(MODELLIB) @$(CMD_FILE) $(LOCAL_USER_OBJS)
	@cmd /C "echo ### Created $(MODELLIB)"
	@cmd /C "echo ### Created library: $@"
 endif
endif

%.obj : %.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : %.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/ert/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

raccel_main.obj : $(MATLAB_ROOT)/rtw/c/raccel/raccel_main.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/rtw/c/raccel/raccel_main.c

raccel_sup.obj : $(MATLAB_ROOT)/rtw/c/raccel/raccel_sup.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/rtw/c/raccel/raccel_sup.c

raccel_mat.obj : $(MATLAB_ROOT)/rtw/c/raccel/raccel_mat.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/rtw/c/raccel/raccel_mat.c

simulink_solver_api.obj : $(MATLAB_ROOT)/simulink/include/simulink_solver_api.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/simulink/include/simulink_solver_api.c

raccel_utils.obj : $(MATLAB_ROOT)/rtw/c/src/rapid/raccel_utils.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/rtw/c/src/rapid/raccel_utils.c

common_utils.obj : $(MATLAB_ROOT)/rtw/c/src/rapid/common_utils.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/rtw/c/src/rapid/common_utils.c

ext_svr.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_svr.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_svr.c

updown.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/updown.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/updown.c

ext_work.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_work.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_work.c

rtiostream_interface.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/rtiostream_interface.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/rtiostream_interface.c

rtiostream_tcpip.obj : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/rtiostream_tcpip.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/rtiostream_tcpip.c

rtiostream_utils.obj : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c



%.obj : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/simulink/src/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/rtiostreamtcpip/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<



# Libraries:





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw
