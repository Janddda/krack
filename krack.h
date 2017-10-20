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
#include <pcap.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>

typedef void (*pcap_cb)(unsigned char*, const struct pcap_pkthdr*, const unsigned char*);

/**
 * Asdf function prototypes.
 */
void usage();

/**
 * Packet / networking related function prototypes.
 */
uint8_t chksum(uint8_t*, int);
void packet_handler(unsigned char*, int);

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
