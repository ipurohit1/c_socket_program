#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h> 

#include <netinet/in.h>

// Workflow
// create socket 
// bind it to an IP and port by setting up a struct
// call the connect method and pass the socket and a struct pointer 
// call recv function to receive data from  server in a buffer string 
// close socket 
int main() {
 
// Create a socket 
int network_socket; 
// First param is domain, second param sets TCP 
network_socket = socket(AF_INET, SOCK_STREAM, 0);

//specify an address for the socket 
struct sockaddr_in server_address; 

// set values in struct 
// same as domain before 
server_address.sin_family = AF_INET; 
server_address.sin_port = htons(9001); 
server_address.sin_addr.s_addr = INADDR_ANY; 

int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

// check if connection worked 
if (connection_status == -1) { 
    printf("There was an error making a connection to the remote socket\n");
}

//receive data from the server
//create a string to store info we get back from server 
char server_response[256]; 
recv(network_socket, &server_response, sizeof(server_response), 0); 

//print out the data that we receive from server 
printf("The server sent the data %s\n", server_response); 

close(network_socket); 

    return 0; 
}