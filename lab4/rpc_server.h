//
// Created by gc on 11/17/16.
//


#ifndef LAB1_RPC_SERVER_H
#define LAB1_RPC_SERVER_H

#include <iostream>
#include <memory>
#include <grpc++/grpc++.h>
#include "graphserver.grpc.pb.h"
#include "Graph.hpp"
#include "rpc_sender.h"

void run_rpc_server(string rpc_port);


#endif //LAB1_RPC_SERVER_H
