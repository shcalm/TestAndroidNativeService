#ifndef TEST_H
#define TEST_H

#include <utils/Log.h>
#include "ITest.h"
namespace android{
class Test : public BnTest{
	public:
	   	inline uint32_t  getTest(){
			ALOGD("getTest===== %d",IPCThreadState::self()->getCallingUid());
			return value;

		}
		inline void setTest(uint32_t par){
			ALOGD("setTest===== %d",IPCThreadState::self()->getCallingUid());
			value = par;
		}
	private:
		uint32_t value;

};
};
#endif
