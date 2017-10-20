#ifndef __krack_h
#define __krack_h

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <getopt.h>

/**
 * Network headers
 */
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>

struct pseudo_header {
    uint32_t src_addr;
    uint32_t dst_addr;
     uint8_t placeholder;
     uint8_t protocol;
    uint16_t tcp_len;
};

uint8_t chksum(uint8_t*, int);
void process_packet(unsigned char*, int);

/**
 * Exploit function prototypes.
 */
void exploit__pk_4way_hs();
void exploit__gk_4way_hs();
void exploit__igk_4way_hs();
void exploit__gk_ri();
void exploit__igk_ri();
void exploit__accept_rftrr_ri_pk();

#endif
