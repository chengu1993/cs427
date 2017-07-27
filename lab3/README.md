## Synopsis

This is the third phase of the project required by CPSC426/526@Yale University. The main goal of this project is to implement the third version of server which is based on lab2. In this project, we add availability to the graph server by replicating graph in two other VMs. The replication protocol is a mixed protocol of Chain Replication and Primary backup. It is a two members' group work.

## VM infromation

### Primary server IP and port
104.197.202.136:8080

### Backup server IP and port
104.197.123.34:8080

104.154.94.227:8080


## Group Members

- **Chen Gu(cg736):** 16Fall master student of Computer Science

- **Ruiming Kou(rk656):** 16Fall master student of Computer Science

## Wordload Division

**Chen Gu:**

- Wrote Makefile
- Implemented -b parameter using getopt
- Rewrote garph server logic to support replication
- Finished integration and conducted overall tests


**Ruiming Kou:**
- set up the Google Cloud VM instance according to the instruction.
- Wrote GRPC definition file protoc.
- Implement RPC sender and RPC server.
