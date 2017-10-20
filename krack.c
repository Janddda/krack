#include "krack.h"

int main(int argc, char** argv) {
    int opt = 0;
    int TOL = 10000;
    
    pcap_t* handle      = NULL;
    char**  filters     = NULL;
    char*   device_name = NULL;
    char    error[PCAP_ERRBUF_SIZE];

    /**
     * i = interface
     * u = usage
     * f = pcap filter file path
     */
    while((opt = getopt(argc, argv, "f:i:u")) != -1) {
        if (optarg == NULL)
            continue;

        switch(opt) {
            case 'f': {
                filters = get_pcap_filters((char*)optarg);
                
                break;
            }

            case 'i': {
                device_name = (char*)optarg;
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

    device_name = pcap_lookupdev(error);

    if (device_name == NULL) {
        fprintf(stderr, "ERROR: %s", error);
        exit(1);
    }

    pcap_create(device_name, error);
    handle = pcap_open_live(device_name, BUFSIZ, 0, TOL, error);
    
    if (pcap_can_set_rfmon(handle) == 0) {
        fprintf(stderr, "Can't put %s into monitor mode!", device_name);
        pcap_close(handle);
        exit(2);
    }

    pcap_set_promisc(handle, 1);
    pcap_set_snaplen(handle, BUFSIZ);
    pcap_set_timeout(handle, TOL);
    pcap_activate(handle);

    printf("-------------------------------------------\n");
    pcap_loop(handle, 0, krack_pcap_handler, NULL);
    pcap_set_promisc(handle, 0);
    pcap_close(handle);
    printf("-------------------------------------------\n");

    return 0;
}

void usage() {

}

char** get_pcap_filters(char* filter_path) {
    char*  path = (filter_path == NULL ? "pcap.filters" : filter_path);
    FILE*  file = fopen(path, "r");
    char*  line = NULL;
    char** filters;

    if (file == NULL) {
        perror("Couldn't open pcap filter file: ");
    }
    
    fclose(file);
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

void krack_pcap_handler(uchar_ptr args, const struct pcap_pkthdr* header, c_uchar_ptr body) {
    printf("packet cap len: %d\n", header->caplen);
    printf("packet total len: %d\n", header->len);
}


