LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	main_test.cpp \
	ITest.cpp \

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libutils \
	liblog \
	libbinder


LOCAL_C_INCLUDES := . \

LOCAL_MODULE:= testservice

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:=\
	testcase.cpp \
	ITest.cpp \

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libutils \
	liblog \
	libbinder

LOCAL_C_INCLUDES := . \

LOCAL_MODULE:= testtest
include $(BUILD_EXECUTABLE)
