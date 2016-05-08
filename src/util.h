#ifndef UTIL_H_
#define UTIL_H_

#include <stdlib.h>
#include <netdb.h>

typedef union {
  struct sockaddr addr;
  struct sockaddr_in addr4;
  struct sockaddr_in6 addr6;
} IPAddr;

#define container_of(ptr, type, field) \
  ((type *) ((char *) (ptr) - ((char *) &((type *) 0)->field)))

#define CHECK(exp) \
do { \
  if (!exp) { \
    fprintf(stderr, "Error occured on [%s:%d] %s()\n", __FILE__, \
        __LINE__, __FUNCTION__); \
    exit(1); \
  } \
} while (0)

void log_ipv4_and_port(void *ipv4, int port, const char *msg);
void log_ipv6_and_port(void *ipv6, int port, const char *msg);
int fill_ipaddr(IPAddr *ipaddr, int port,  char *ipstr, 
    int ipstr_len, struct addrinfo *ai);

#endif /* end of include guard: UTIL_H_ */
