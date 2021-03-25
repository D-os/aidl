#include <android/aidl/tests/IOldName.h>
#include <android/aidl/tests/BpOldName.h>

namespace android {

namespace aidl {

namespace tests {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(OldName, "android.aidl.tests.IOldName")

}  // namespace tests

}  // namespace aidl

}  // namespace android
#include <android/aidl/tests/BpOldName.h>
#include <android/aidl/tests/BnOldName.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace aidl {

namespace tests {

BpOldName::BpOldName(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IOldName>(_aidl_impl){
}

::android::binder::Status BpOldName::RealName(::android::String16* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remote());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnOldName::TRANSACTION_RealName, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IOldName::getDefaultImpl())) {
     return IOldName::getDefaultImpl()->RealName(_aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readString16(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace tests

}  // namespace aidl

}  // namespace android
#include <android/aidl/tests/BnOldName.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace aidl {

namespace tests {

BnOldName::BnOldName()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnOldName::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnOldName::TRANSACTION_RealName:
  {
    ::android::String16 _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(RealName(&_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeString16(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  default:
  {
    _aidl_ret_status = ::android::BBinder::onTransact(_aidl_code, _aidl_data, _aidl_reply, _aidl_flags);
  }
  break;
  }
  if (_aidl_ret_status == ::android::UNEXPECTED_NULL) {
    _aidl_ret_status = ::android::binder::Status::fromExceptionCode(::android::binder::Status::EX_NULL_POINTER).writeToParcel(_aidl_reply);
  }
  return _aidl_ret_status;
}

}  // namespace tests

}  // namespace aidl

}  // namespace android
