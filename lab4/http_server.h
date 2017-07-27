//
// Created by Chen Gu on 12/11/16.
//

#ifndef LAB1_HTTP_SERVER_H
#define LAB1_HTTP_SERVER_H

#include <string>
#include <iostream>
#include <thread>
#include "frozen.h"
#include "mongoose.h"
#include "Graph.hpp"
#include "rpc_sender.h"


void run_http_server(char *http_port, int partnum, vector<string> partlist);

#endif //LAB1_HTTP_SERVER_H
