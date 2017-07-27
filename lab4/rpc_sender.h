//
// Created by gc on 11/17/16.
//

#include <iostream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include "graphserver.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using graphserver::Request;
using graphserver::Reply;
using graphserver::HelloRequest;
using graphserver::HelloReply;
using graphserver::Greeter;



#ifndef LAB1_RPC_SENDER_H
#define LAB1_RPC_SENDER_H


class RPC_Sender {
public:

    RPC_Sender(std::shared_ptr<Channel> channel)
    : stub_(Greeter::NewStub(channel)) {}


    // Assambles the client's payload, sends it and presents the response back
    // from the server.
    std::string SayHello(const std::string& user) {
        // Data we are sending to the server.
        HelloRequest request;
        request.set_name(user);

        // Container for the data we expect from the server.
        HelloReply reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        Status status = stub_->SayHello(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
            return reply.message();
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                      << std::endl;
            return "RPC failed";
        }
    }

    bool add_edge(uint64_t node_a_id, uint64_t node_b_id);

    bool remove_edge(uint64_t node_a_id, uint64_t node_b_id);

private:
    std::unique_ptr<Greeter::Stub> stub_;

};

#endif //LAB1_RPC_SENDER_H


