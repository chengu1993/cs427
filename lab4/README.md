## Synopsis

This is the fourth phase of the project required by CPSC426/526@Yale University. The main goal of this lab is to add feature like scalibity to the orignal graph server using partition method. It is a two members' group work.

## Group Members

- **Chen Gu(cg736):** 16Fall master student of Computer Science

- **Ruiming Kou(rk656):** 16Fall master student of Computer Science

## Wordload Division

**Chen Gu:**

- Wrote Makefile
- Using getopt to parse -p and -l optional arguments
- Rewrote http server logic to perform partition

| Function      	  | File       	|
|:---------------:	  |:------------:	|
| `add_node`    	| graph.cpp  	|
| `add_edge`    	| graph.cpp  	|


**Ruiming Kou:**

- Wrote GRPC definition file protoc.
- Implement RPC sender and RPC server.
- Finished integration and conducted overall tests

