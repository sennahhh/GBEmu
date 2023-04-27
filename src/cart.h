#ifndef CART_H
#define CART_H
#include <stdint.h>

struct parsed_cart get_cart(char *rom_path);

struct parsed_cart {
    char *rom_path;
    uint8_t entry_point[4]; 
    uint8_t nintendo_logo[48];  
    char title[16];          
    char *license_publisher;
    uint8_t SGB_flag;
    char *cart_type;      
    long rom_size;       
    long ram_size;
    uint8_t dest_code; 
    uint8_t version_of_game;
    uint8_t header_checksum;
    uint8_t global_checksum[2];
    uint8_t full_rom[];
};

#endif