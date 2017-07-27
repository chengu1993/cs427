#include <iostream>
#include "frozen.h"
#include "mongoose.h"
#include "Utils.hpp"
#include "Graph.hpp"

static char *http_port = "8080";
static const mg_str s_post_method = MG_MK_STR("POST");
Graph *graph = new Graph();


static void event_handler(struct mg_connection *c, int event, void *p){
    static const struct mg_str api_prefix = MG_MK_STR("/api/v1/");
    struct mg_str graph_method;

    if(event == MG_EV_HTTP_REQUEST){
        std::cout<<"Received a HTTP request"<<std::endl;
        struct http_message *hm = (struct http_message *) p;
        if(has_prefix(&hm->uri, &api_prefix)){
            graph_method.p = hm->uri.p + api_prefix.len;
            graph_method.len = hm->uri.len - api_prefix.len;
            if(is_equal(&hm->method, &s_post_method)){
                std::cout<<"Received a POST request"<<std::endl;

                /**parse node_id*/
                char *node_a = NULL;
                char *node_b = NULL;
                //TODO: change either the type of both ids or their value
                uint64_t node_a_id = -1, node_b_id = -1;
                json_scanf(hm->body.p, hm->body.len, "{node_id:%Q}", &node_a);
                if(node_a != NULL){
                    node_a_id = strtoull(node_a, NULL,0);
                } else{
                    json_scanf(hm->body.p, hm->body.len, "{node_a_id:%Q, node_b_id:%Q}", &node_a, &node_b);
                    node_a_id = strtoull(node_a, NULL, 0);
                    node_b_id = strtoull(node_b, NULL, 0);
                }
                if(node_a == NULL && node_b == NULL) return;
                string body;
                int status_code = -1;
                if(is_equal(&graph_method, &graph_add_node)){
                    std::cout<<"Received a add_node request"<<std::endl;
                    pair<int, int> result = graph->add_node(node_a_id);
                    status_code = result.first;
                    body = string(hm->body.p);
                    body = body.substr(0, hm->body.len);
                } else if(is_equal(&graph_method, &graph_add_edge)){
                    std::cout<<"Received a add_edge request"<<std::endl;
                    pair<int, int> result = graph->add_edge(node_a_id, node_b_id);
                    status_code = result.first;
                    body = string(hm->body.p);
                    body = body.substr(0, hm->body.len);
                } else if(is_equal(&graph_method, &graph_remove_node)){
                    std::cout<<"Received a remove_node request"<<std::endl;
                    pair<int, int> result = graph->remove_node(node_a_id);
                    status_code = result.first;
                    body = string(hm->body.p);
                    body = body.substr(0, hm->body.len);
                } else if(is_equal(&graph_method, &graph_remove_edge)){
                    std::cout<<"Received a remove_edge request"<<std::endl;
                    pair<int, int> result = graph->remove_edge(node_a_id, node_b_id);
                    status_code = result.first;
                    body = string(hm->body.p);
                    body = body.substr(0, hm->body.len);
                } else if(is_equal(&graph_method, &graph_get_node)){
                    std::cout<<"Received a get_node request"<<std::endl;
                    pair<int, int> result = graph->get_node(node_a_id);
                    status_code = result.first;
                    body = "{\"in_graph\": ";
                    body += result.second ? "TRUE}" : "FALSE}";
                } else if(is_equal(&graph_method, &graph_get_edge)){
                    std::cout<<"Received a get_edge request"<<std::endl;
                    pair<int, int> result = graph->get_edge(node_a_id, node_b_id);
                    status_code = result.first;
                    body = "{\"in_graph\": ";
                    body += result.second ? "TRUE}" : "FALSE}";
                } else if(is_equal(&graph_method, &graph_get_neighbors)){
                    std::cout<<"Received a get_neighbors request"<<std::endl;
                    //TODO: this return value is only for test temporarily, must be changed later
                    pair<int, unordered_set<uint64_t>> result = graph->get_neighbors(node_a_id);

                    status_code = result.first;
                    unordered_set<uint64_t> neighbors = result.second;
                    body = string(hm->body.p).substr(0, hm->body.len-1);
                    body += ",\"neighbors\": [";

                    for(auto it = neighbors.begin(); it != neighbors.end(); it++){
                        body += to_string(*it) + ",";
                    }
                    if(body[body.length()-1] == ',') body = body.substr(0, body.length()-1);
                    body +=  "]}";

                } else if(is_equal(&graph_method, &graph_shorest_path)){
                    std::cout<<"Received a shortest_path request"<<std::endl;
                    pair<int, uint64_t > result = graph->shortest_path(node_a_id, node_b_id);
                    status_code = result.first;
                    body = "{\"distance\": " + to_string(result.second) + "}";

                } else{
                    std::cout<<"Operation not supported yet"<<std::endl;
                };

                switch (status_code){
                    case 1: status_code = http_200_response;break;
                    case 0: status_code = http_204_response;break;
                    case -1: status_code = http_400_response;break;
                    default: status_code = http_400_response;break;
                }

                switch (status_code){
                    case http_200_response:
                        mg_send_head(c, 200, body.length(), "Content-Type text/json");
                        mg_printf(c, "%.*s", body.length(), body.c_str());
                        break;
                    case http_204_response:
                        mg_send_head(c, 204, 0, "Content-Type text/json");
                        break;
                    case http_400_response:
                        mg_send_head(c, 400, 0, "Content-Type text/json");
                        break;
                }
            }
            else{
                std::cout<<"Operation Not supported yet."<<std::endl;
            }
        }
        else {

        }

    }
}


int main(int argc, char*argv[]) {
    http_port = argv[1];
    struct mg_mgr mgr;
    struct mg_connection *c;
    mg_mgr_init(&mgr, NULL);
    c = mg_bind(&mgr, http_port, event_handler);
    mg_set_protocol_http_websocket(c);
    std::cout<< "Server running on "<<http_port<<std::endl;
    for(;;){
        mg_mgr_poll(&mgr, 1000);
    }
    mg_mgr_free(&mgr);
    return 0;
}
