// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: graphserver.proto

#ifndef PROTOBUF_graphserver_2eproto__INCLUDED
#define PROTOBUF_graphserver_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace graphserver {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_graphserver_2eproto();
void protobuf_AssignDesc_graphserver_2eproto();
void protobuf_ShutdownFile_graphserver_2eproto();

class HelloReply;
class HelloRequest;
class Reply;
class Request;

// ===================================================================

class Request : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:graphserver.Request) */ {
 public:
  Request();
  virtual ~Request();

  Request(const Request& from);

  inline Request& operator=(const Request& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Request& default_instance();

  void Swap(Request* other);

  // implements Message ----------------------------------------------

  inline Request* New() const { return New(NULL); }

  Request* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Request& from);
  void MergeFrom(const Request& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Request* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint64 node_a_id = 1;
  void clear_node_a_id();
  static const int kNodeAIdFieldNumber = 1;
  ::google::protobuf::uint64 node_a_id() const;
  void set_node_a_id(::google::protobuf::uint64 value);

  // optional uint64 node_b_id = 2;
  void clear_node_b_id();
  static const int kNodeBIdFieldNumber = 2;
  ::google::protobuf::uint64 node_b_id() const;
  void set_node_b_id(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:graphserver.Request)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::uint64 node_a_id_;
  ::google::protobuf::uint64 node_b_id_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_graphserver_2eproto();
  friend void protobuf_AssignDesc_graphserver_2eproto();
  friend void protobuf_ShutdownFile_graphserver_2eproto();

  void InitAsDefaultInstance();
  static Request* default_instance_;
};
// -------------------------------------------------------------------

class Reply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:graphserver.Reply) */ {
 public:
  Reply();
  virtual ~Reply();

  Reply(const Reply& from);

  inline Reply& operator=(const Reply& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Reply& default_instance();

  void Swap(Reply* other);

  // implements Message ----------------------------------------------

  inline Reply* New() const { return New(NULL); }

  Reply* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Reply& from);
  void MergeFrom(const Reply& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Reply* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bool succ = 1;
  void clear_succ();
  static const int kSuccFieldNumber = 1;
  bool succ() const;
  void set_succ(bool value);

  // @@protoc_insertion_point(class_scope:graphserver.Reply)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  bool succ_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_graphserver_2eproto();
  friend void protobuf_AssignDesc_graphserver_2eproto();
  friend void protobuf_ShutdownFile_graphserver_2eproto();

  void InitAsDefaultInstance();
  static Reply* default_instance_;
};
// -------------------------------------------------------------------

class HelloRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:graphserver.HelloRequest) */ {
 public:
  HelloRequest();
  virtual ~HelloRequest();

  HelloRequest(const HelloRequest& from);

  inline HelloRequest& operator=(const HelloRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const HelloRequest& default_instance();

  void Swap(HelloRequest* other);

  // implements Message ----------------------------------------------

  inline HelloRequest* New() const { return New(NULL); }

  HelloRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const HelloRequest& from);
  void MergeFrom(const HelloRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(HelloRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // @@protoc_insertion_point(class_scope:graphserver.HelloRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_graphserver_2eproto();
  friend void protobuf_AssignDesc_graphserver_2eproto();
  friend void protobuf_ShutdownFile_graphserver_2eproto();

  void InitAsDefaultInstance();
  static HelloRequest* default_instance_;
};
// -------------------------------------------------------------------

class HelloReply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:graphserver.HelloReply) */ {
 public:
  HelloReply();
  virtual ~HelloReply();

  HelloReply(const HelloReply& from);

  inline HelloReply& operator=(const HelloReply& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const HelloReply& default_instance();

  void Swap(HelloReply* other);

  // implements Message ----------------------------------------------

  inline HelloReply* New() const { return New(NULL); }

  HelloReply* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const HelloReply& from);
  void MergeFrom(const HelloReply& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(HelloReply* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string message = 1;
  void clear_message();
  static const int kMessageFieldNumber = 1;
  const ::std::string& message() const;
  void set_message(const ::std::string& value);
  void set_message(const char* value);
  void set_message(const char* value, size_t size);
  ::std::string* mutable_message();
  ::std::string* release_message();
  void set_allocated_message(::std::string* message);

  // @@protoc_insertion_point(class_scope:graphserver.HelloReply)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr message_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_graphserver_2eproto();
  friend void protobuf_AssignDesc_graphserver_2eproto();
  friend void protobuf_ShutdownFile_graphserver_2eproto();

  void InitAsDefaultInstance();
  static HelloReply* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Request

// optional uint64 node_a_id = 1;
inline void Request::clear_node_a_id() {
  node_a_id_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Request::node_a_id() const {
  // @@protoc_insertion_point(field_get:graphserver.Request.node_a_id)
  return node_a_id_;
}
inline void Request::set_node_a_id(::google::protobuf::uint64 value) {
  
  node_a_id_ = value;
  // @@protoc_insertion_point(field_set:graphserver.Request.node_a_id)
}

// optional uint64 node_b_id = 2;
inline void Request::clear_node_b_id() {
  node_b_id_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Request::node_b_id() const {
  // @@protoc_insertion_point(field_get:graphserver.Request.node_b_id)
  return node_b_id_;
}
inline void Request::set_node_b_id(::google::protobuf::uint64 value) {
  
  node_b_id_ = value;
  // @@protoc_insertion_point(field_set:graphserver.Request.node_b_id)
}

// -------------------------------------------------------------------

// Reply

// optional bool succ = 1;
inline void Reply::clear_succ() {
  succ_ = false;
}
inline bool Reply::succ() const {
  // @@protoc_insertion_point(field_get:graphserver.Reply.succ)
  return succ_;
}
inline void Reply::set_succ(bool value) {
  
  succ_ = value;
  // @@protoc_insertion_point(field_set:graphserver.Reply.succ)
}

// -------------------------------------------------------------------

// HelloRequest

// optional string name = 1;
inline void HelloRequest::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& HelloRequest::name() const {
  // @@protoc_insertion_point(field_get:graphserver.HelloRequest.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HelloRequest::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:graphserver.HelloRequest.name)
}
inline void HelloRequest::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:graphserver.HelloRequest.name)
}
inline void HelloRequest::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:graphserver.HelloRequest.name)
}
inline ::std::string* HelloRequest::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:graphserver.HelloRequest.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* HelloRequest::release_name() {
  // @@protoc_insertion_point(field_release:graphserver.HelloRequest.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HelloRequest::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:graphserver.HelloRequest.name)
}

// -------------------------------------------------------------------

// HelloReply

// optional string message = 1;
inline void HelloReply::clear_message() {
  message_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& HelloReply::message() const {
  // @@protoc_insertion_point(field_get:graphserver.HelloReply.message)
  return message_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HelloReply::set_message(const ::std::string& value) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:graphserver.HelloReply.message)
}
inline void HelloReply::set_message(const char* value) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:graphserver.HelloReply.message)
}
inline void HelloReply::set_message(const char* value, size_t size) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:graphserver.HelloReply.message)
}
inline ::std::string* HelloReply::mutable_message() {
  
  // @@protoc_insertion_point(field_mutable:graphserver.HelloReply.message)
  return message_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* HelloReply::release_message() {
  // @@protoc_insertion_point(field_release:graphserver.HelloReply.message)
  
  return message_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HelloReply::set_allocated_message(::std::string* message) {
  if (message != NULL) {
    
  } else {
    
  }
  message_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), message);
  // @@protoc_insertion_point(field_set_allocated:graphserver.HelloReply.message)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace graphserver

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_graphserver_2eproto__INCLUDED
