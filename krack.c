#include "krack.h"

int main(int argc, char** argv) {
    int opt  = 0;
    int sock = 0;
    const uint16_t TIMEOUT_LIMIT = 10000;
    
    pcap_if_t *alldevsp = NULL;
    pcap_if_t *device   = NULL;
    pcap_t    *handle   = NULL;

    char* device_name;
    char  error[PCAP_ERRBUF_SIZE];
    char  devices[100][100];

    /**
     * i = interface
     * u = usage
     */
    while((opt = getopt(argc, argv, "i:u")) != -1) {
        if (optarg == NULL)
            continue;

        switch(opt) {
            case 'i': {
                device_name = optarg;
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

//    if (!(size_t)strlen(device_name)) {
//        if (pcap_findalldevs(&alldevsp, error) == -1) {
//            fprintf(stderr, "ERROR: couldn't find any devices!: %s", error);
//            exit(1);
//        }
//        uint8_t device_counter = 1;
//        for (device = alldevsp; device != NULL; device = device->next) {
//            printf("%d. %s - %s\n", device_counter, device->name, device->description);
//            if (device->name != NULL) {
//                strcpy(devices[device_counter - 1], device->name);
//                device_counter++;
//            }
//        } 
//    }

    device_name = pcap_lookupdev(error);

    if (device_name == NULL) {
        fprintf(stderr, "ERROR: %s", error);
        exit(1);
    }

    handle = pcap_open_live(device_name, BUFSIZ, 0, TIMEOUT_LIMIT, error);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device_name, error);
        exit(1);
    }
/*
    while (1) {
        int saddr_size = sizeof(saddr);
        int data_size  = recvfrom(sock, buffer, buff_size, 0, &saddr, &saddr_size);

        if (data_size < 0) {
            printf("Failed to recv any more packets from src.");
            return 1;
        }

        process_packet(buffer, data_size);
    }

    close(sock);
*/
    return 0;
}

void usage() {

}

/**
 * 
 */
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
void packet_handler(unsigned char* buffer, int size) {

}


