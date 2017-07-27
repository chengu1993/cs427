## Synopsis

This is the first phase of the project required by CPSC426/526@Yale University. The main goal of this project is to implement the first version of server which stores undirected graphs. It is a two members' group work.

## Group Members

- **Chen Gu(cg736):** 16Fall master student of Computer Science

- **Ruiming Kou(rk656):** 16Fall master student of Computer Science

## Wordload Division

**Chen Gu:**

- Wrote Makefile
- Implemented a HTTP server to receive requests and parse requests using Mongoose library
- implemented the function to Parse JSON content using Frozen library
- Designed and implemented the data structure for undirected graph
- implemented the functions in the table below
- Finished integration and conducted overall tests

| Function      	  | File       	|
|:---------------:	  |:------------:	|
| `add_node`    	| graph.cpp  	|
| `add_edge`    	| graph.cpp  	|


**Ruiming Kou:**
The implementation of the following functions and classes:


| Function      	  | File       	|
|:---------------:	  |:------------:	|
| `remove_node`    	| graph.cpp  	|
| `remove_edge`   	| graph.cpp  	|
| `get_node`      	| graph.cpp  	|
| `get_edge`      	| graph.cpp  	|
| `get_neighbors` 	| graph.cpp 	|
| `shortest_path` 	|graph.cpp/getTheShortestPath.cpp/candidateNode.cpp 	|
