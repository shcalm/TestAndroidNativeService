#ifndef ITEST_H
#define ITEST_H
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android{
class ITest : public IInterface{

	public:
		DECLARE_META_INTERFACE(Test);
		virtual uint32_t getTest() = 0;
		virtual void setTest(uint32_t ) = 0;
};

class BnTest : public BnInterface<ITest>{

	public:
		virtual status_t  onTransact(uint32_t code,
								  const Parcel& data,
								  Parcel* reply,
								  uint32_t flags= 0 );

};
};
#endif//ITEST_H
