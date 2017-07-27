#include <iostream>
#include <memory>
#include <grpc++/grpc++.h>
#include "graphserver.grpc.pb.h"
#include "rpc_server.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using graphserver::HelloRequest;
using graphserver::HelloReply;
using graphserver::Request;
using graphserver::Reply;
using graphserver::Greeter;


static string rpc_port = "8000";
static string local_host = "0.0.0.0";
extern Graph *graph;
extern std::mutex mtx;

// Logic and data behind the server's behavior.
class GreeterServiceImpl final : public Greeter::Service {
private:




public:

    Status SayHello(ServerContext* context, const HelloRequest* request, HelloReply* reply) override {
        cout<<"receives hello request"<<endl;
        std::string prefix("Hello ");
        reply->set_message(prefix + request->name());
        return Status::OK;
    }

    Status add_edge(ServerContext* context, const Request* request, Reply* reply) override {
        mtx.lock();
        cout<<"Received an add-edge request"<<endl;
        uint64_t node_a_id = request->node_a_id();
        uint64_t node_b_id = request->node_b_id();

        pair<int, int> res = graph->get_edge(node_a_id, node_b_id);
        if(res.first == -1 || res.second == 1){
            reply->set_succ(false);
            mtx.unlock();
            return Status::CANCELLED;
        }
        pair<int, int> result = graph->add_edge(node_a_id, node_b_id);
        if(result.first != 1){
            reply->set_succ(false);
            mtx.unlock();
            return Status::CANCELLED;
        }
        reply->set_succ(true);
        mtx.unlock();
        return Status::OK;
    }

    Status remove_edge(ServerContext* context, const Request* request, Reply* reply) override {
        mtx.lock();
        cout<<"Received an remove-edge request"<<endl;
        uint64_t node_a_id = request->node_a_id();
        uint64_t node_b_id = request->node_b_id();

        pair<int, int> res = graph->get_edge(node_a_id, node_b_id);
        if(res.first == -1 || res.second == 0){
            reply->set_succ(false);
            mtx.unlock();
            return Status::CANCELLED;
        }
        pair<int, int> result = graph->remove_edge(node_a_id, node_b_id);
        if(result.first != 1){
            reply->set_succ(false);
            mtx.unlock();
            return Status::CANCELLED;
        }
        reply->set_succ(true);
        mtx.unlock();
        return Status::OK;
    }
};

void run_rpc_server(string rpc_port) {
  std::string server_address = "0.0.0.0:" + rpc_port;

  GreeterServiceImpl *service = new GreeterServiceImpl();

  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "RPC Server listening on " << server_address << std::endl;
  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

