#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h> 

#include <netinet/in.h>

// Workflow
// create socket 
// bind that socket to an IP and port where it can listen for connections 
// accept a connection 
// send or recv data to the socket that it connected to 

int main() {
    char server_message[256] = "Success: you have reached the server";

    // create the server socket, intended for listening
    int server_socket; 
    server_socket = socket(AF_INET, SOCK_STREAM, 0); 

    //define the server address 
    struct sockaddr_in server_address; 
    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(9001); 
    server_address.sin_addr.s_addr = INADDR_ANY; 

    //bind the socket to the specified IP and port 
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)); 

    // Takes in the socket and how many connections it can take 
    listen(server_socket, 1); 

    int client_socket; 
    client_socket = accept(server_socket, NULL, NULL); 

    // send message 
    send(client_socket, server_message, sizeof(server_message), 0); 

    close(server_socket); 

    return 0; 
}