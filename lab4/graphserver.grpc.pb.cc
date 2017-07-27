// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: graphserver.proto

#include "graphserver.pb.h"
#include "graphserver.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace graphserver {

static const char* Greeter_method_names[] = {
  "/graphserver.Greeter/SayHello",
  "/graphserver.Greeter/add_node",
  "/graphserver.Greeter/add_edge",
  "/graphserver.Greeter/remove_node",
  "/graphserver.Greeter/remove_edge",
};

std::unique_ptr< Greeter::Stub> Greeter::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< Greeter::Stub> stub(new Greeter::Stub(channel));
  return stub;
}

Greeter::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_SayHello_(Greeter_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_add_node_(Greeter_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_add_edge_(Greeter_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_remove_node_(Greeter_method_names[3], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_remove_edge_(Greeter_method_names[4], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Greeter::Stub::SayHello(::grpc::ClientContext* context, const ::graphserver::HelloRequest& request, ::graphserver::HelloReply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_SayHello_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::graphserver::HelloReply>* Greeter::Stub::AsyncSayHelloRaw(::grpc::ClientContext* context, const ::graphserver::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::graphserver::HelloReply>(channel_.get(), cq, rpcmethod_SayHello_, context, request);
}

::grpc::Status Greeter::Stub::add_node(::grpc::ClientContext* context, const ::graphserver::Request& request, ::graphserver::Reply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_add_node_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::graphserver::Reply>* Greeter::Stub::Asyncadd_nodeRaw(::grpc::ClientContext* context, const ::graphserver::Request& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::graphserver::Reply>(channel_.get(), cq, rpcmethod_add_node_, context, request);
}

::grpc::Status Greeter::Stub::add_edge(::grpc::ClientContext* context, const ::graphserver::Request& request, ::graphserver::Reply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_add_edge_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::graphserver::Reply>* Greeter::Stub::Asyncadd_edgeRaw(::grpc::ClientContext* context, const ::graphserver::Request& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::graphserver::Reply>(channel_.get(), cq, rpcmethod_add_edge_, context, request);
}

::grpc::Status Greeter::Stub::remove_node(::grpc::ClientContext* context, const ::graphserver::Request& request, ::graphserver::Reply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_remove_node_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::graphserver::Reply>* Greeter::Stub::Asyncremove_nodeRaw(::grpc::ClientContext* context, const ::graphserver::Request& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::graphserver::Reply>(channel_.get(), cq, rpcmethod_remove_node_, context, request);
}

::grpc::Status Greeter::Stub::remove_edge(::grpc::ClientContext* context, const ::graphserver::Request& request, ::graphserver::Reply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_remove_edge_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::graphserver::Reply>* Greeter::Stub::Asyncremove_edgeRaw(::grpc::ClientContext* context, const ::graphserver::Request& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::graphserver::Reply>(channel_.get(), cq, rpcmethod_remove_edge_, context, request);
}

Greeter::Service::Service() {
  (void)Greeter_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      Greeter_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Greeter::Service, ::graphserver::HelloRequest, ::graphserver::HelloReply>(
          std::mem_fn(&Greeter::Service::SayHello), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      Greeter_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Greeter::Service, ::graphserver::Request, ::graphserver::Reply>(
          std::mem_fn(&Greeter::Service::add_node), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      Greeter_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Greeter::Service, ::graphserver::Request, ::graphserver::Reply>(
          std::mem_fn(&Greeter::Service::add_edge), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      Greeter_method_names[3],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Greeter::Service, ::graphserver::Request, ::graphserver::Reply>(
          std::mem_fn(&Greeter::Service::remove_node), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      Greeter_method_names[4],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< Greeter::Service, ::graphserver::Request, ::graphserver::Reply>(
          std::mem_fn(&Greeter::Service::remove_edge), this)));
}

Greeter::Service::~Service() {
}

::grpc::Status Greeter::Service::SayHello(::grpc::ServerContext* context, const ::graphserver::HelloRequest* request, ::graphserver::HelloReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Greeter::Service::add_node(::grpc::ServerContext* context, const ::graphserver::Request* request, ::graphserver::Reply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Greeter::Service::add_edge(::grpc::ServerContext* context, const ::graphserver::Request* request, ::graphserver::Reply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Greeter::Service::remove_node(::grpc::ServerContext* context, const ::graphserver::Request* request, ::graphserver::Reply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Greeter::Service::remove_edge(::grpc::ServerContext* context, const ::graphserver::Request* request, ::graphserver::Reply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace graphserver
