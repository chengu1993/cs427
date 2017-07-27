CXXFLAGS = -O1 -g -Wall -std=c++14
OBJ = main.o mongoose.o frozen.o candidateNode.o getTheShortestPath.o Graph.o
TARGET = cs426_graph_server
#rulse
all : $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)

#dependencies
main.o : main.cpp mongoose.h frozen.h Utils.hpp Graph.hpp
frozen.o : frozen.c frozen.h
Graph.o: Graph.cpp Graph.hpp
mongoose.o : mongoose.c mongoose.h
candidateNode.o: candidateNode.cpp candidateNode.hpp
getTheShortestPath.o: getTheShortestPath.cpp getTheShortestPath.hpp
