#include <iostream>
#include <thread>
#include "mongoose.h"
#include "rpc_server.h"
#include "http_server.h"

int main(int argc, char*argv[]) {

    char *partnum = NULL;
    char *http_port = NULL;
    vector<string> partlist;
    if(optind < argc){
        http_port = argv[optind++];
    }
    int c;

    while ((c = getopt (argc, argv, "p:l:")) != -1)
        switch (c)
        {
            case 'p':
                partnum = optarg;
                break;
            case 'l':
                partlist.push_back(string(optarg));
                while(optind < argc){
                    partlist.push_back(string(argv[optind++]));
                }
                break;
            default:
                abort();
        }

    //Parse RPC port
    string local_address = partlist[atoi(partnum)-1];
    string rpc_port = local_address.substr(local_address.find(':') + 1, local_address.length());
    //Initialize RPC server
    std::thread rpc_server(run_rpc_server, rpc_port);

    //Initialize HTTP server
    std::thread http_server(run_http_server, http_port, atoi(partnum), partlist);

    //wait for join
    rpc_server.join();
    http_server.join();
    return 0;
}
