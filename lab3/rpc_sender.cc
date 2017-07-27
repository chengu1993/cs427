#include "rpc_sender.h"


bool RPC_Sender::add_node(uint64_t node_id) {
    //Wrap request
    Request request;
    request.set_node_a_id(node_id);

    //Wrap reply and context
    Reply reply;
    ClientContext context;

    //The actutal RPC
    Status status = stub_->add_node(&context, request, &reply);
//    std::count<<"RPC send to" + ip + ":" + port<<endl;
    std::cout<<"RPC send add node" << std::endl;
    // Act upon its status.
    if (status.ok()) {

        std::cout<<"RPC receive add node reply1" << std::endl;
        return reply.succ();
    } else {

        std::cout<<"RPC receive add node reply2" << std::endl;
        std::cout << status.error_code() << ": " << status.error_message()
                  << std::endl;
        return false;

    }

}

bool RPC_Sender::add_edge(uint64_t node_a_id, uint64_t node_b_id) {
    //Wrap request
    Request request;
    request.set_node_a_id(node_a_id);
    request.set_node_b_id(node_b_id);
    //Wrap reply and context
    Reply reply;
    ClientContext context;
    std::cout<<"RPC send add edge" << std::endl;
    //The actutal RPC
    Status status = stub_->add_edge(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
        return reply.succ();
    } else {
        std::cout << status.error_code() << ": " << status.error_message()
                  << std::endl;
        return false;
    }
}

bool RPC_Sender::remove_node(uint64_t node_id) {
    //Wrap request
    Request request;
    request.set_node_a_id(node_id);

    //Wrap reply and context
    Reply reply;
    ClientContext context;
    std::cout<<"RPC send remove node" << std::endl;
    //The actutal RPC
    Status status = stub_->remove_node(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
        return reply.succ();
    } else {
        std::cout << status.error_code() << ": " << status.error_message()
                  << std::endl;
        return false;
    }
}

bool RPC_Sender::remove_edge(uint64_t node_a_id, uint64_t node_b_id) {
    //Wrap request
    Request request;
    request.set_node_a_id(node_a_id);
    request.set_node_b_id(node_b_id);
    //Wrap reply and context
    Reply reply;
    ClientContext context;
    std::cout<<"RPC send remove node" << std::endl;
    //The actutal RPC
    Status status = stub_->remove_node(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
        return reply.succ();
    } else {
        std::cout << status.error_code() << ": " << status.error_message()
                  << std::endl;
        return false;
    }
}

