//
// Created by Chen Gu on 12/11/16.
//

#include "http_server.h"




static string http_port = "8080";
static const mg_str s_post_method = MG_MK_STR("POST");
int partnum;
vector<string> partlist;
extern Graph *graph;
extern std::mutex mtx;

static const int http_200_response = 200;
static const int http_204_response = 204;
static const int http_400_response = 400;


static int has_prefix(const struct mg_str *uri, const struct mg_str *prefix) {
    return uri->len > prefix->len && memcmp(uri->p, prefix->p, prefix->len) == 0;
}

static int is_equal(const struct mg_str *s1, const struct mg_str *s2) {
    return s1->len == s2->len && memcmp(s1->p, s2->p, s2->len) == 0;
}

static void event_handler(struct mg_connection *c, int event, void *p){
//    cout<<"Start"<<endl;
    mtx.lock();
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
                    u_int64_t min_id = min(node_a_id, node_b_id);
                    u_int64_t max_id = max(node_a_id, node_b_id);

                    status_code = graph->get_node(min_id).second;
                    if (status_code == 1) {//check whether min_id exists in local partition
                        status_code = graph->get_edge(min_id, max_id).second;
                        if (status_code == 0) {//check whether this edge already exists
                            u_int64_t next_partition_id = max_id % 3;
                            RPC_Sender sender(grpc::CreateChannel(partlist[next_partition_id],
                                                                  grpc::InsecureChannelCredentials()));
                            bool succ = sender.add_edge(max_id, min_id);

                            if (succ) {
                                cout<<"Succ"<<endl;
                                graph->add_edge(min_id, max_id);
                                status_code = 1;
                                body = string(hm->body.p);
                                body = body.substr(0, hm->body.len);
                            } else{
                                status_code = -1;
                            }
                        } else {
                            status_code = 0;
                        }
                    }

                } else if(is_equal(&graph_method, &graph_remove_edge)){
                    std::cout<<"Received a remove_edge request"<<std::endl;
                    u_int64_t min_id = min(node_a_id, node_b_id);
                    u_int64_t max_id = max(node_a_id, node_b_id);

                    status_code = graph->get_node(min_id).second;
                    if (status_code == 1) {//check whether min_id exists in local partition
                        status_code = graph->get_edge(min_id, max_id).second;
                        if (status_code == 1) {//check whether this edge already exists
                            u_int64_t next_partition_id = max_id % 3;
                            RPC_Sender sender(grpc::CreateChannel(partlist[next_partition_id],
                                                                  grpc::InsecureChannelCredentials()));
                            bool succ = sender.remove_edge(max_id, min_id);
                            if (succ) {
                                cout<<"Succ"<<endl;
                                graph->remove_edge(min_id, max_id);
                                status_code = 1;
                                body = string(hm->body.p);
                                body = body.substr(0, hm->body.len);
                            } else{
                                status_code = -1;
                            }
                        }
                    }
                } else if(is_equal(&graph_method, &graph_get_node)){
                    std::cout<<"Received a get_node request"<<std::endl;
                    pair<int, int> result = graph->get_node(node_a_id);
                    status_code = result.first;
                    body = "{\"in_graph\": ";
                    body += result.second ? "TRUE}" : "FALSE}";
                } else if(is_equal(&graph_method, &graph_get_edge)){
                    std::cout<<"Received a get_edge request"<<std::endl;
                    u_int64_t from_id, to_id;
                    if((node_a_id % partlist.size()) == partnum){
                        from_id = node_a_id;
                        to_id = node_b_id;
                    } else{
                        from_id = node_b_id;
                        to_id = node_a_id;
                    }
                    pair<int, int> result = graph->get_edge(from_id, to_id);
                    status_code = result.first;
                    body = "{\"in_graph\": ";
                    body += result.second ? "TRUE}" : "FALSE}";
                } else if(is_equal(&graph_method, &graph_get_neighbors)){
                    std::cout<<"Received a get_neighbors request"<<std::endl;
                    pair<int, unordered_set<uint64_t>> result = graph->get_neighbors(node_a_id);
                    status_code = result.first;
                    unordered_set<uint64_t> neighbors = result.second;
                    body = string(hm->body.p).substr(0, hm->body.len - 1);
                    body += ",\"neighbors\": [";
                    for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
                        body += to_string(*it) + ",";
                    }
                    if (body[body.length() - 1] == ',') body = body.substr(0, body.length() - 1);
                    body += "]}";
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
                        mg_printf(c, "%.*s", (int)body.length(), body.c_str());
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
//    cout<<"End"<<endl;
    mtx.unlock();
}



void run_http_server(char *http_port, int p, vector<string> t){
    struct mg_mgr mgr;
    struct mg_connection *c;
    partnum = p - 1;
    partlist = t;
    mg_mgr_init(&mgr, NULL);
    c = mg_bind(&mgr, http_port, event_handler);
    mg_set_protocol_http_websocket(c);
    std::cout<< "HTTP Server running on "<<http_port<<std::endl;
    for(;;){
        mg_mgr_poll(&mgr, 1000);
    }
    mg_mgr_free(&mgr);
}