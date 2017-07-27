## Synopsis

This is the second phase of the project required by CPSC426/526@Yale University. The main goal of this project is to implement the second version of server which stores undirected graphs. In this project, we realized the storage of updating log and the function of checkpoint. It is a two members' group work.

## Google cloud IP
**Chen Gu(cg736):** 104.154.45.187:8080

**Ruiming Kou(rk656):** 104.154.152.177:8080


## Group Members

- **Chen Gu(cg736):** 16Fall master student of Computer Science

- **Ruiming Kou(rk656):** 16Fall master student of Computer Science

## Wordload Division

**Chen Gu:**

- Set up the Google Cloud VM instance according to the instruction
- Implemented the functions in the table below
- Changed Mongoose library to support 507 response
- Re-implemented server logic to record operations and give response.
- Finished integration and conducted overall tests

| Function      	        | File            	|
|:---------------:	      |:------------:   	|
| `write_super_block`    	| FileSystem.cpp  	|
| `read_super_block`    	| FileSystem.cpp  	|
| `checksum`    	          | FileSystem.cpp  	|
| `record`    	          | FileSystem.cpp  	|
| `format`    	          | FileSystem.cpp  	|
| `startup (part of)`    	| FileSystem.cpp  	|



**Ruiming Kou:**
- set up the Google Cloud VM instance according to the instruction.
- The implementation of the following functions and classes:

| Function      	        | File       	      |
|:---------------:	      |:------------:	    |
| `checkpoint`    	      | FileSystem.cpp  	|
| `startup (part of)`   	| FileSystem.cpp  	|
| `transfer_to_map`      	| FileSystem.cpp  	|
| `transfer_to_struct`    | FileSystem.cpp  	|
