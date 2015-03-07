#include "ITest.h"
#include <binder/Parcel.h>
namespace android{
enum{
	GET_Test = 1,
	SET_Test,
};
class BpTest: public BpInterface<ITest>{
	public:
		BpTest(const sp<IBinder>& impl)
			: BpInterface<ITest>(impl){
		}

		virtual uint32_t getTest(){
			Parcel data,reply;
			data.writeInterfaceToken(ITest::getInterfaceDescriptor());
			remote()->transact(GET_Test,data,&reply);
			return reply.readInt32();

		}
		virtual void setTest(uint32_t params){
			Parcel data,reply;
			data.writeInterfaceToken(ITest::getInterfaceDescriptor());
			data.writeInt32(params);
			remote()->transact(SET_Test,data,&reply);
			return;
		
		}


};
IMPLEMENT_META_INTERFACE(Test,"android.Test.ITest");

status_t BnTest::onTransact(uint32_t code,
							const Parcel& data,
							Parcel* reply,
							uint32_t flags){
	switch(code){
		case GET_Test:{
			CHECK_INTERFACE(ITest,data,reply);
			reply->writeInt32(getTest());
			return NO_ERROR;
			}break;
		case SET_Test:{
			CHECK_INTERFACE(ITest,data,reply);
			uint32_t value = data.readInt32();
			setTest(value);
			
			return NO_ERROR;
			}break;
		default:
		return BBinder::onTransact(code, data, reply, flags);
		
	
	}
	


}

};
