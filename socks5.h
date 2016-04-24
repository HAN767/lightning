#ifndef SOCKS5_H_
#define SOCKS5_H_
#include <stdint.h>

#define SOCKS5_VERSION 5

typedef enum {
  S5_PARSE_STATE_VERSION,
  S5_PARSE_STATE_NMETHODS,
  S5_PARSE_STATE_METHODS,
  S5_PARSE_STATE_REQ_VERSION,
  S5_PARSE_STATE_REQ_CMD,
  S5_PARSE_STATE_REQ_RSV,
  S5_PARSE_STATE_REQ_ATYP,
  S5_PARSE_STATE_REQ_DST_ADDR_LEN,
  S5_PARSE_STATE_REQ_DST_ADDR,
  S5_PARSE_STATE_REQ_DST_PORT,
  S5_PARSE_STATE_FINISH,
} Socks5State;

typedef enum {
  S5_ATYP_IPV4 = 1,
  S5_ATYP_DOMAIN = 3,
  S5_ATYP_IPV6 = 4
} Socks5Atyp;

typedef enum {
  S5_AUTH_NONE = 0,
  S5_AUTH_GSSAPI = 1,
  S5_AUTH_PASSWD = 2
} Socks5AuthMethod;

typedef enum {
  S5_BAD_VERSION = -5,
  S5_JUNK_DATA_IN_HANDSHAKE = -4,
  S5_JUN_DATA_IN_REQUEST = -3,
  S5_UNSUPPORTED_CMD = -2,
  S5_BAD_ATYP = -1,
  S5_OK = 0,
} S5Err;

typedef struct {
  Socks5State state;
  uint8_t arg_index;
  uint8_t arg_count;
  uint8_t methods;
  uint8_t cmd;
  uint8_t atyp;
  uint8_t dst_addr[257];  // max=0xFF, one more byte for the terminating null
  uint16_t dst_port;
} Socks5Ctx;

S5Err socks5_parse_handshake(Socks5Ctx *socks5_ctx, const char *data, int size);
S5Err socks5_parse_req(Socks5Ctx *socks5_ctx, const char *data, int size);

#endif /* end of include guard: SOCKS5_H_ */
