//
// Created by gc on 11/17/16.
//
#include <iostream>
#include <memory>
#include <grpc++/grpc++.h>
#include "graphserver.grpc.pb.h"
#include "Graph.hpp"
#include "FileSystem.hpp"
#include "rpc_sender.h"

#ifndef LAB1_RPC_SERVER_H
#define LAB1_RPC_SERVER_H



void run_rpc_server(string ip, FileSystem *fileSystem, Graph *graph);


#endif //LAB1_RPC_SERVER_H
