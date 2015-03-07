/*
**
** Copyright 2008, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/


#include <fcntl.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <cutils/properties.h>
#include <utils/Log.h>

#include <cutils/properties.h>

#include "Test.h"
using namespace android;



int main(int argc, char** argv)
{
	sp<IServiceManager> sm = defaultServiceManager();
	sp<ITest> service = interface_cast<ITest>(sm->getService(String16("service.test")));
	service->setTest(1);
	ALOGD("log = %d",service->getTest());	
	printf("log = %d",service->getTest());
	return 0;	
			
}
