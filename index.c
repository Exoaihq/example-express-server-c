It's important to note that converting this code directly to C might not be the best approach, as C doesn't have built-in support for web servers like Node.js does. However, I can provide you with a simple example of a C program that creates a basic web server using the  socket  library.

   c
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int server_fd, new_socket;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  const int port = 3000;

  char buffer[1024] = {0};
  char response[] = HTTP/1.1 200 OKnContent-Type: text/plainnContent-Length: 13nnHello, World!;

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror(socket failed);
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror(bind failed);
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0) {
    perror(listen failed);
    exit(EXIT_FAILURE);
  }

  printf(Server is running on http://localhost:%dn, port);

  while (true) {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
      perror(accept failed);
      exit(EXIT_FAILURE);
    }

    read(new_socket, buffer, 1024);
    send(new_socket, response, strlen(response), 0);
    close(new_socket);
  }

  return 0;
}
   

To compile and run this code, save it to a file called  web_server.c  and use the following command:

   
gcc web_server.c -o web_server && ./web_server
   

Keep in mind that this is a very basic example and lacks many features of a full-fledged web server. For more advanced web server functionality in C, you might want to look into libraries like [libevent](https://libevent.org/) or [mongoose](https://github.com/cesanta/mongoose).
