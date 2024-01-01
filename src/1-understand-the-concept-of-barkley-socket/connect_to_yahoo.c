#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  // Create a socket
  int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    printf("Failed to create socket\n");
    return 1;
  }

  // Set up the server address
  struct sockaddr_in server;
  server.sin_addr.s_addr =
      inet_addr("183.79.250.123"); // IP address of google.com
  server.sin_family = AF_INET;
  server.sin_port = htons(80); // HTTP port

  // Connect to the server
  if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Failed to connect\n");
    return 1;
  }
  printf("Connected to yahoo.co.jp\n");

  // Close the socket
  close(socket_desc);

  return 0;
}
