/**
 * @Author:     Dillan Hildebrand
 *
 * @Disclaimer: I did not find these vulnerabilities but
 *              simply implemented PoC exploits based on
 *              documentation publicly available online.
 *
 * @License:    MIT
 */
#include "krack.h"


/**
 * Globals
 */
uintmax_t total = 0;


int main(int argc, char** argv) {

    int opt = 0;
    while((opt = getopt(argc, argv, "e:t:u")) != -1) {
        if (optarg == NULL)
            continue;

        switch(opt) {
            case 'e': {
                break;
            }

            case 't': {
                break;
            }
            
            case 'u': {
                usage();
                break;
            }

            default: {
                break;
            }
        }
    }

    return 0;
}

uint8_t chksum(uint8_t* ptr, int nbytes) {
    uint8_t odd_byte;
    register long sum = 0;
    register int8_t answer;
    
    while (nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }

    if (nbytes == 1) {
        odd_byte = 0;
        *((unsigned char*)&odd_byte) = *(unsigned char*)ptr;
        sum += odd_byte;
    }

    return answer; 
}

/**
 * Process each packet.
 */
void process_packet(unsigned char* buffer, int size) {
    struct iphdr* ip_hdr = (struct iphdr*)buffer;
}
