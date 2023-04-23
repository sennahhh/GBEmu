#include <stdint.h>
#include <stdio.h>

struct cart_header {
    uint8_t entry_point[4]; 
    uint8_t nintendo_logo[48];  
    char title[16];          
    char *publisher;
    uint8_t SGB_flag;
    char *cart_type;      
    int rom_size;       
    int ram_size;
    uint8_t dest_code; 
    uint8_t version_of_game;
    uint8_t header_checksum;
    uint16_t global_checksum;
};

struct cart_header parsed_cart_header;
unsigned char full_cart_header[80];

int read_cart_header(char *rom_path) {

    FILE *fp;

    fp = fopen(rom_path, "rb");
    if(fp == NULL) {
        return 1;
    }

    fseek(fp, 256, 1);
    fread(full_cart_header, 1, 80, fp);

    return 0;
}

int parse_cart_header() {
    int i = 0;
    int j = 0;
    // entry point
    for(i = i; i < 4; i++) {
        parsed_cart_header.entry_point[i] = full_cart_header[i];
    }

    // nintendo logo
    for(j = 0; i < 48; i++) {
        parsed_cart_header.nintendo_logo[j] = full_cart_header[i];
        j++;
    }

    // title
    for(j = 0; i < 16; i++) {
        parsed_cart_header.title[j] = full_cart_header[i];
        j++;
    }

    printf("%c\n", parsed_cart_header.title[0]);
    
    return 0;
}