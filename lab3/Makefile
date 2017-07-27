CPPFLAGS += -I/usr/local/include -pthread
CXXFLAGS += -std=c++11
LDFLAGS += -L/usr/local/lib `pkg-config --libs grpc++ grpc`       \
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed \
           -lprotobuf -lpthread -ldl

PROTOC = protoc
GRPC_CPP_PLUGIN = grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN)`

PROTOS_PATH = ./protos

vpath %.proto $(PROTOS_PATH)



OBJ = main.o mongoose.o frozen.o candidateNode.o getTheShortestPath.o Graph.o FileSystem.o graphserver.pb.o graphserver.grpc.pb.o rpc_sender.o rpc_server.o
TARGET = cs426_graph_server

#rulse


.PRECIOUS: %.grpc.pb.cc
%.grpc.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=. --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) $<

.PRECIOUS: %.pb.cc
%.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=. $<


all : $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $^ $(LDFLAGS) -o $@

#rpc_server: graphserver.pb.o graphserver.grpc.pb.o rpc_server.o
#	$(CXX) $^ $(LDFLAGS) -o $@

#rpc_sender: graphserver.pb.o graphserver.grpc.pb.o rpc_sender.o
#	$(CXX) $^ $(LDFLAGS) -o $@



clean:
	rm -f $(OBJ) $(TARGET) *.o


#dependencies
main.o : main.cpp mongoose.h frozen.h Utils.hpp Graph.hpp FileSystem.hpp rpc_sender.h rpc_server.h
frozen.o : frozen.c frozen.h
Graph.o: Graph.cpp Graph.hpp
FileSystem.o: FileSystem.hpp FileSystem.cpp Graph.hpp
mongoose.o : mongoose.c mongoose.h
candidateNode.o: candidateNode.cpp candidateNode.hpp
getTheShortestPath.o: getTheShortestPath.cpp getTheShortestPath.hpp
graphserver.grpc.pb.o: graphserver.grpc.pb.cc graphserver.grpc.pb.h
graphserver.pb.o: graphserver.pb.cc graphserver.pb.h
rpc_sender.o: rpc_sender.cc rpc_sender.h graphserver.grpc.pb.h graphserver.pb.h
rpc_server.o: rpc_server.cc rpc_server.h graphserver.grpc.pb.h graphserver.pb.h
