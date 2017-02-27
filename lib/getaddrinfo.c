#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char* program) {
  printf("Usage: %s <address>\n", program);
  exit(1);
}

int main(int argc, char** argv) {
  if (argc != 2) {
    usage(argv[0]);
  }

  char* address = argv[1];

  struct addrinfo* results;

  int err = getaddrinfo(address, NULL, NULL, &results);

  if (err != 0) {
    fprintf(stderr, "Error resolving address %s: %s\n", address, gai_strerror(err));
    exit(1);
  }

  struct addrinfo* result;

  for (result = results; result != NULL; result = result->ai_next) {
    struct sockaddr *ai_addr = result->ai_addr;
    struct sockaddr_in *addr_in4;
    struct sockaddr_in6 *addr_in6;
    char* sa_data;
    int hexlen;
    char *addr_s = NULL;
    char *byte_s = NULL;

    switch(result->ai_family) {
      case AF_INET:
        addr_in4 = (struct sockaddr_in *) ai_addr;
        addr_s = malloc(INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(addr_in4->sin_addr), addr_s, INET_ADDRSTRLEN);
        break;
      case AF_INET6:
        addr_in6 = (struct sockaddr_in6 *) ai_addr;
        addr_s = malloc(INET6_ADDRSTRLEN);
        inet_ntop(AF_INET6, &(addr_in6->sin6_addr), addr_s, INET6_ADDRSTRLEN);
        break;
      default:
        sa_data = ai_addr->sa_data;
        hexlen = 1 + 2 * result->ai_addrlen;
        addr_s = malloc(hexlen);
        byte_s = malloc(3);

        for (int i = 0; i < result->ai_addrlen; i++) {
          snprintf(byte_s, 3, "%02x", sa_data[i]);
          strcat(addr_s, byte_s);
        }

        free(byte_s);
    }

    printf("%s\n", addr_s);

    free(addr_s);
  }

  return 0;
}
