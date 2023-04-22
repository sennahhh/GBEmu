#include <stdint.h>
#include <stdio.h>

struct rom_header {
    uint32_t entry_point;    // 4 bytes
    uint8_t nintendo_logo;  // 48 bytes
    uint8_t title;          // 16 bytes
    uint8_t cart_type;      // 1 byte
    uint8_t rom_size;       // 1 byte
    uint8_t ram_size;       // 1 byte



};

int read_cart_header(char *rom_path) {

    FILE *fp;
    unsigned char *rom_header[80];

    fp = fopen(rom_path, "rb");
    if(fp == NULL) {
        return 1;
    }

    fseek(fp, 256, 1);
    fread(rom_header, 1, 80, fp);

    return 0;
}