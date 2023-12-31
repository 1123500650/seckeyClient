// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RespondProtobuf.proto
// Protobuf C++ Version: 4.26.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_RespondProtobuf_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_RespondProtobuf_2eproto_2epb_2eh

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

#define PROTOBUF_INTERNAL_EXPORT_RespondProtobuf_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_RespondProtobuf_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_RespondProtobuf_2eproto;
namespace protobuf {
class RespondProto;
struct RespondProtoDefaultTypeInternal;
extern RespondProtoDefaultTypeInternal _RespondProto_default_instance_;
}  // namespace protobuf
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace protobuf {

// ===================================================================


// -------------------------------------------------------------------

class RespondProto final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:protobuf.RespondProto) */ {
 public:
  inline RespondProto() : RespondProto(nullptr) {}
  ~RespondProto() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR RespondProto(
      ::google::protobuf::internal::ConstantInitialized);

  inline RespondProto(const RespondProto& from) : RespondProto(nullptr, from) {}
  RespondProto(RespondProto&& from) noexcept : RespondProto() {
    *this = ::std::move(from);
  }

  inline RespondProto& operator=(const RespondProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline RespondProto& operator=(RespondProto&& from) noexcept {
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
  static const RespondProto& default_instance() {
    return *internal_default_instance();
  }
  static inline const RespondProto* internal_default_instance() {
    return reinterpret_cast<const RespondProto*>(
        &_RespondProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(RespondProto& a, RespondProto& b) { a.Swap(&b); }
  inline void Swap(RespondProto* other) {
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
  void UnsafeArenaSwap(RespondProto* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  RespondProto* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<RespondProto>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const RespondProto& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const RespondProto& from) { RespondProto::MergeImpl(*this, from); }

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
  void InternalSwap(RespondProto* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "protobuf.RespondProto"; }

 protected:
  explicit RespondProto(::google::protobuf::Arena* arena);
  RespondProto(::google::protobuf::Arena* arena, const RespondProto& from);
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kClientIdFieldNumber = 2,
    kServerIdFieldNumber = 3,
    kDataFieldNumber = 4,
    kStautsFieldNumber = 1,
    kSeckeyIdFieldNumber = 5,
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
  // bytes serverId = 3;
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
  // bytes data = 4;
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
  // int32 stauts = 1;
  void clear_stauts() ;
  ::int32_t stauts() const;
  void set_stauts(::int32_t value);

  private:
  ::int32_t _internal_stauts() const;
  void _internal_set_stauts(::int32_t value);

  public:
  // int32 seckeyId = 5;
  void clear_seckeyid() ;
  ::int32_t seckeyid() const;
  void set_seckeyid(::int32_t value);

  private:
  ::int32_t _internal_seckeyid() const;
  void _internal_set_seckeyid(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:protobuf.RespondProto)
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
    ::google::protobuf::internal::ArenaStringPtr serverid_;
    ::google::protobuf::internal::ArenaStringPtr data_;
    ::int32_t stauts_;
    ::int32_t seckeyid_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_RespondProtobuf_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// RespondProto

// int32 stauts = 1;
inline void RespondProto::clear_stauts() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.stauts_ = 0;
}
inline ::int32_t RespondProto::stauts() const {
  // @@protoc_insertion_point(field_get:protobuf.RespondProto.stauts)
  return _internal_stauts();
}
inline void RespondProto::set_stauts(::int32_t value) {
  _internal_set_stauts(value);
  // @@protoc_insertion_point(field_set:protobuf.RespondProto.stauts)
}
inline ::int32_t RespondProto::_internal_stauts() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.stauts_;
}
inline void RespondProto::_internal_set_stauts(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.stauts_ = value;
}

// bytes clientId = 2;
inline void RespondProto::clear_clientid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.clientid_.ClearToEmpty();
}
inline const std::string& RespondProto::clientid() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:protobuf.RespondProto.clientId)
  return _internal_clientid();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void RespondProto::set_clientid(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.clientid_.SetBytes(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:protobuf.RespondProto.clientId)
}
inline std::string* RespondProto::mutable_clientid() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_clientid();
  // @@protoc_insertion_point(field_mutable:protobuf.RespondProto.clientId)
  return _s;
}
inline const std::string& RespondProto::_internal_clientid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.clientid_.Get();
}
inline void RespondProto::_internal_set_clientid(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.clientid_.Set(value, GetArena());
}
inline std::string* RespondProto::_internal_mutable_clientid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.clientid_.Mutable( GetArena());
}
inline std::string* RespondProto::release_clientid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:protobuf.RespondProto.clientId)
  return _impl_.clientid_.Release();
}
inline void RespondProto::set_allocated_clientid(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.clientid_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.clientid_.IsDefault()) {
          _impl_.clientid_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:protobuf.RespondProto.clientId)
}

// bytes serverId = 3;
inline void RespondProto::clear_serverid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.serverid_.ClearToEmpty();
}
inline const std::string& RespondProto::serverid() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:protobuf.RespondProto.serverId)
  return _internal_serverid();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void RespondProto::set_serverid(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.serverid_.SetBytes(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:protobuf.RespondProto.serverId)
}
inline std::string* RespondProto::mutable_serverid() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_serverid();
  // @@protoc_insertion_point(field_mutable:protobuf.RespondProto.serverId)
  return _s;
}
inline const std::string& RespondProto::_internal_serverid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.serverid_.Get();
}
inline void RespondProto::_internal_set_serverid(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.serverid_.Set(value, GetArena());
}
inline std::string* RespondProto::_internal_mutable_serverid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.serverid_.Mutable( GetArena());
}
inline std::string* RespondProto::release_serverid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:protobuf.RespondProto.serverId)
  return _impl_.serverid_.Release();
}
inline void RespondProto::set_allocated_serverid(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.serverid_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.serverid_.IsDefault()) {
          _impl_.serverid_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:protobuf.RespondProto.serverId)
}

// bytes data = 4;
inline void RespondProto::clear_data() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.data_.ClearToEmpty();
}
inline const std::string& RespondProto::data() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:protobuf.RespondProto.data)
  return _internal_data();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void RespondProto::set_data(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.data_.SetBytes(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:protobuf.RespondProto.data)
}
inline std::string* RespondProto::mutable_data() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_data();
  // @@protoc_insertion_point(field_mutable:protobuf.RespondProto.data)
  return _s;
}
inline const std::string& RespondProto::_internal_data() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.data_.Get();
}
inline void RespondProto::_internal_set_data(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.data_.Set(value, GetArena());
}
inline std::string* RespondProto::_internal_mutable_data() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.data_.Mutable( GetArena());
}
inline std::string* RespondProto::release_data() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:protobuf.RespondProto.data)
  return _impl_.data_.Release();
}
inline void RespondProto::set_allocated_data(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.data_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.data_.IsDefault()) {
          _impl_.data_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:protobuf.RespondProto.data)
}

// int32 seckeyId = 5;
inline void RespondProto::clear_seckeyid() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.seckeyid_ = 0;
}
inline ::int32_t RespondProto::seckeyid() const {
  // @@protoc_insertion_point(field_get:protobuf.RespondProto.seckeyId)
  return _internal_seckeyid();
}
inline void RespondProto::set_seckeyid(::int32_t value) {
  _internal_set_seckeyid(value);
  // @@protoc_insertion_point(field_set:protobuf.RespondProto.seckeyId)
}
inline ::int32_t RespondProto::_internal_seckeyid() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.seckeyid_;
}
inline void RespondProto::_internal_set_seckeyid(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.seckeyid_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_RespondProtobuf_2eproto_2epb_2eh
