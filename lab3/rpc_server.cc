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



// Logic and data behind the server's behavior.
class GreeterServiceImpl final : public Greeter::Service {
private:

    FileSystem* fileSystem = NULL;
    Graph* graph = NULL;
    string next_node_ip;


public:

    GreeterServiceImpl(string next_node_ip, FileSystem* fileSystem, Graph* graph){
        this->fileSystem = fileSystem;
        this->graph = graph;
        this->next_node_ip = next_node_ip;

    }

    Status SayHello(ServerContext* context, const HelloRequest* request, HelloReply* reply) override {
        cout<<"receives hello request"<<endl;
        std::string prefix("Hello ");
        reply->set_message(prefix + request->name());
        return Status::OK;
    }

    Status add_node(ServerContext* context, const Request* request, Reply* reply) override {

        uint64_t node_a_id = request->node_a_id();
        cout<<"Received an add-node request"<<endl;
        cout<<"next:" << next_node_ip<<endl;
        cout<<"localhost:" << local_host<<endl;
        if(next_node_ip != local_host){
            cout<<"Send to next Replicat"<<endl;
            RPC_Sender sender(grpc::CreateChannel(
                    next_node_ip +":" +rpc_port, grpc::InsecureChannelCredentials()));
            bool succ = sender.add_node(node_a_id);
            if(!succ) {
                reply->set_succ(false);
                return Status::CANCELLED;
            }
        }

        pair<int, int> log_res = fileSystem->record(0, node_a_id, NULL);
        int status_code = log_res.first;
        if (status_code != 1) {
            reply->set_succ(false);
            return Status::CANCELLED;
        }
        pair<int, int> result = graph->add_node(node_a_id);
        reply->set_succ(true);
        return Status::OK;
    }


    Status add_edge(ServerContext* context, const Request* request, Reply* reply) override {

        cout<<"Received an add-edge request"<<endl;
        uint64_t node_a_id = request->node_a_id();
        uint64_t node_b_id = request->node_b_id();
        if(next_node_ip != local_host){
            RPC_Sender sender(grpc::CreateChannel(
                    next_node_ip +":" +rpc_port, grpc::InsecureChannelCredentials()));
            bool succ = sender.add_edge(node_a_id, node_b_id);
            if(!succ) {
                reply->set_succ(false);
                return Status::CANCELLED;
            }
        }
        pair<int, int> log_res = fileSystem->record(1, node_a_id, node_b_id);
        int status_code = log_res.first;
        if (status_code != 1) {
            reply->set_succ(false);
            return Status::CANCELLED;
        }
        pair<int, int> result = graph->add_edge(node_a_id, node_b_id);
        reply->set_succ(true);
        return Status::OK;
    }


    Status remove_node(ServerContext* context, const Request* request, Reply* reply) override {

        cout<<"Received an remove-node request"<<endl;
        uint64_t node_a_id = request->node_a_id();
        if(next_node_ip != local_host){
            RPC_Sender sender(grpc::CreateChannel(
                    next_node_ip +":" +rpc_port, grpc::InsecureChannelCredentials()));
            bool succ = sender.remove_node(node_a_id);
            if(!succ) {
                reply->set_succ(false);
                return Status::CANCELLED;
            }
        }

        pair<int, int> log_res = fileSystem->record(2, node_a_id, NULL);
        int status_code = log_res.first;
        if (status_code != 1) {
            reply->set_succ(false);
            return Status::CANCELLED;
        }
        pair<int, int> result = graph->remove_node(node_a_id);
        reply->set_succ(true);
        return Status::OK;
    }


    Status remove_edge(ServerContext* context, const Request* request, Reply* reply) override {
        cout<<"Received an remove-edge request"<<endl;
        uint64_t node_a_id = request->node_a_id();
        uint64_t node_b_id = request->node_b_id();
        if(next_node_ip != local_host){
            RPC_Sender sender(grpc::CreateChannel(
                    next_node_ip +":" +rpc_port, grpc::InsecureChannelCredentials()));
            bool succ = sender.remove_edge(node_a_id, node_b_id);
            if(!succ) {
                reply->set_succ(false);
                return Status::CANCELLED;
            }
        }

        pair<int, int> log_res = fileSystem->record(3, node_a_id, node_b_id);
        int status_code = log_res.first;
        if (status_code != 1) {
            reply->set_succ(false);
            return Status::CANCELLED;
        }
        pair<int, int> result = graph->remove_edge(node_a_id, node_b_id);
        reply->set_succ(true);
        return Status::OK;
    }


};

void run_rpc_server(string ip, FileSystem *fileSystem, Graph *graph) {
  std::string server_address("0.0.0.0:8000");

  GreeterServiceImpl *service = new GreeterServiceImpl(ip, fileSystem, graph);

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

