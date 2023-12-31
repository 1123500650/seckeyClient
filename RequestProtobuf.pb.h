// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RequestProtobuf.proto
// Protobuf C++ Version: 4.26.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_RequestProtobuf_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_RequestProtobuf_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025000 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_RequestProtobuf_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_RequestProtobuf_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_RequestProtobuf_2eproto;
namespace protobuf {
class RequestProtobuf;
struct RequestProtobufDefaultTypeInternal;
extern RequestProtobufDefaultTypeInternal _RequestProtobuf_default_instance_;
}  // namespace protobuf
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace protobuf {

// ===================================================================


// -------------------------------------------------------------------

class RequestProtobuf final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:protobuf.RequestProtobuf) */ {
 public:
  inline RequestProtobuf() : RequestProtobuf(nullptr) {}
  ~RequestProtobuf() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR RequestProtobuf(
      ::google::protobuf::internal::ConstantInitialized);

  inline RequestProtobuf(const RequestProtobuf& from) : RequestProtobuf(nullptr, from) {}
  RequestProtobuf(RequestProtobuf&& from) noexcept : RequestProtobuf() {
    *this = ::std::move(from);
  }

  inline RequestProtobuf& operator=(const RequestProtobuf& from) {
    CopyFrom(from);
    return *this;
  }
  inline RequestProtobuf& operator=(RequestProtobuf&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const RequestProtobuf& default_instance() {
    return *internal_default_instance();
  }
  static inline const RequestProtobuf* internal_default_instance() {
    return reinterpret_cast<const RequestProtobuf*>(
        &_RequestProtobuf_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(RequestProtobuf& a, RequestProtobuf& b) { a.Swap(&b); }
  inline void Swap(RequestProtobuf* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RequestProtobuf* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  RequestProtobuf* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<RequestProtobuf>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const RequestProtobuf& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const RequestProtobuf& from) { RequestProtobuf::MergeImpl(*this, from); }

  private:
  static void MergeImpl(::google::protobuf::Message& to_msg,
                        const ::google::protobuf::Message& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(RequestProtobuf* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "protobuf.RequestProtobuf"; }

 protected:
  explicit RequestProtobuf(::google::protobuf::Arena* arena);
  RequestProtobuf(::google::protobuf::Arena* arena, const RequestProtobuf& from);
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kClientIdFieldNumber = 2,
    kSignFieldNumber = 3,
    kServerIdFieldNumber = 4,
    kDataFieldNumber = 5,
    kCmdTypeFieldNumber = 1,
  };
  // bytes clientId = 2;
  void clear_clientid() ;
  const std::string& clientid() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_clientid(Arg_&& arg, Args_... args);
  std::string* mutable_clientid();
  PROTOBUF_NODISCARD std::string* release_clientid();
  void set_allocated_clientid(std::string* value);

  private:
  const std::string& _internal_clientid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_clientid(
      const std::string& value);
  std::string* _internal_mutable_clientid();

  public:
  // bytes sign = 3;
  void clear_sign() ;
  const std::string& sign() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_sign(Arg_&& arg, Args_... args);
  std::string* mutable_sign();
  PROTOBUF_NODISCARD std::string* release_sign();
  void set_allocated_sign(std::string* value);

  private:
  const std::string& _internal_sign() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_sign(
      const std::string& value);
  std::string* _internal_mutable_sign();

  public:
  // bytes serverId = 4;
  void clear_serverid() ;
  const std::string& serverid() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_serverid(Arg_&& arg, Args_... args);
  std::string* mutable_serverid();
  PROTOBUF_NODISCARD std::string* release_serverid();
  void set_allocated_serverid(std::string* value);

  private:
  const std::string& _internal_serverid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_serverid(
      const std::string& value);
  std::string* _internal_mutable_serverid();

  public:
  // bytes data = 5;
  void clear_data() ;
  const std::string& data() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_data(Arg_&& arg, Args_... args);
  std::string* mutable_data();
  PROTOBUF_NODISCARD std::string* release_data();
  void set_allocated_data(std::string* value);

  private:
  const std::string& _internal_data() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_data(
      const std::string& value);
  std::string* _internal_mutable_data();

  public:
  // int32 cmdType = 1;
  void clear_cmdtype() ;
  ::int32_t cmdtype() const;
  void set_cmdtype(::int32_t value);

  private:
  ::int32_t _internal_cmdtype() const;
  void _internal_set_cmdtype(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:protobuf.RequestProtobuf)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      3, 5, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::ArenaStringPtr clientid_;
    ::google::protobuf::internal::ArenaStringPtr sign_;
    ::google::protobuf::internal::ArenaStringPtr serverid_;
    ::google::protobuf::internal::ArenaStringPtr data_;
    ::int32_t cmdtype_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_RequestProtobuf_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// RequestProtobuf

// int32 cmdType = 1;
inline void RequestProtobuf::clear_cmdtype() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.cmdtype_ = 0;
}
inline ::int32_t RequestProtobuf::cmdtype() const {
  // @@protoc_insertion_point(field_get:protobuf.RequestProtobuf.cmdType)
  return _internal_cmdtype();
}
inline void RequestProtobuf::set_cmdtype(::int32_t value) {
  _internal_set_cmdtype(value);
  // @@protoc_insertion_point(field_set:protobuf.RequestProtobuf.cmdType)
}
inline ::int32_t RequestProtobuf::_internal_cmdtype() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.cmdtype_;
}
inline void RequestProtobuf::_internal_set_cmdtype(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.cmdtype_ = value;
}

// bytes clientId = 2;
inline void RequestProtobuf::clear_clientid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.clientid_.ClearToEmpty();
}
inline const std::string& RequestProtobuf::clientid() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:protobuf.RequestProtobuf.clientId)
  return _internal_clientid();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void RequestProtobuf::set_clientid(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.clientid_.SetBytes(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:protobuf.RequestProtobuf.clientId)
}
inline std::string* RequestProtobuf::mutable_clientid() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_clientid();
  // @@protoc_insertion_point(field_mutable:protobuf.RequestProtobuf.clientId)
  return _s;
}
inline const std::string& RequestProtobuf::_internal_clientid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.clientid_.Get();
}
inline void RequestProtobuf::_internal_set_clientid(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.clientid_.Set(value, GetArena());
}
inline std::string* RequestProtobuf::_internal_mutable_clientid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.clientid_.Mutable( GetArena());
}
inline std::string* RequestProtobuf::release_clientid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:protobuf.RequestProtobuf.clientId)
  return _impl_.clientid_.Release();
}
inline void RequestProtobuf::set_allocated_clientid(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.clientid_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.clientid_.IsDefault()) {
          _impl_.clientid_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:protobuf.RequestProtobuf.clientId)
}

// bytes sign = 3;
inline void RequestProtobuf::clear_sign() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.sign_.ClearToEmpty();
}
inline const std::string& RequestProtobuf::sign() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:protobuf.RequestProtobuf.sign)
  return _internal_sign();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void RequestProtobuf::set_sign(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.sign_.SetBytes(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:protobuf.RequestProtobuf.sign)
}
inline std::string* RequestProtobuf::mutable_sign() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_sign();
  // @@protoc_insertion_point(field_mutable:protobuf.RequestProtobuf.sign)
  return _s;
}
inline const std::string& RequestProtobuf::_internal_sign() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.sign_.Get();
}
inline void RequestProtobuf::_internal_set_sign(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.sign_.Set(value, GetArena());
}
inline std::string* RequestProtobuf::_internal_mutable_sign() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.sign_.Mutable( GetArena());
}
inline std::string* RequestProtobuf::release_sign() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:protobuf.RequestProtobuf.sign)
  return _impl_.sign_.Release();
}
inline void RequestProtobuf::set_allocated_sign(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.sign_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.sign_.IsDefault()) {
          _impl_.sign_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:protobuf.RequestProtobuf.sign)
}

// bytes serverId = 4;
inline void RequestProtobuf::clear_serverid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.serverid_.ClearToEmpty();
}
inline const std::string& RequestProtobuf::serverid() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:protobuf.RequestProtobuf.serverId)
  return _internal_serverid();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void RequestProtobuf::set_serverid(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.serverid_.SetBytes(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:protobuf.RequestProtobuf.serverId)
}
inline std::string* RequestProtobuf::mutable_serverid() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_serverid();
  // @@protoc_insertion_point(field_mutable:protobuf.RequestProtobuf.serverId)
  return _s;
}
inline const std::string& RequestProtobuf::_internal_serverid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.serverid_.Get();
}
inline void RequestProtobuf::_internal_set_serverid(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.serverid_.Set(value, GetArena());
}
inline std::string* RequestProtobuf::_internal_mutable_serverid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.serverid_.Mutable( GetArena());
}
inline std::string* RequestProtobuf::release_serverid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:protobuf.RequestProtobuf.serverId)
  return _impl_.serverid_.Release();
}
inline void RequestProtobuf::set_allocated_serverid(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.serverid_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.serverid_.IsDefault()) {
          _impl_.serverid_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:protobuf.RequestProtobuf.serverId)
}

// bytes data = 5;
inline void RequestProtobuf::clear_data() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.data_.ClearToEmpty();
}
inline const std::string& RequestProtobuf::data() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:protobuf.RequestProtobuf.data)
  return _internal_data();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void RequestProtobuf::set_data(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.data_.SetBytes(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:protobuf.RequestProtobuf.data)
}
inline std::string* RequestProtobuf::mutable_data() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_data();
  // @@protoc_insertion_point(field_mutable:protobuf.RequestProtobuf.data)
  return _s;
}
inline const std::string& RequestProtobuf::_internal_data() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.data_.Get();
}
inline void RequestProtobuf::_internal_set_data(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.data_.Set(value, GetArena());
}
inline std::string* RequestProtobuf::_internal_mutable_data() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.data_.Mutable( GetArena());
}
inline std::string* RequestProtobuf::release_data() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:protobuf.RequestProtobuf.data)
  return _impl_.data_.Release();
}
inline void RequestProtobuf::set_allocated_data(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.data_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.data_.IsDefault()) {
          _impl_.data_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:protobuf.RequestProtobuf.data)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_RequestProtobuf_2eproto_2epb_2eh
