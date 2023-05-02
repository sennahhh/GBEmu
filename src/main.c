#include <stdio.h>
#include <stdlib.h>
#include "emu.h"
#include "cart.h"


int main(int argc, char **argv) {
    
    if(argc >= 2) {
        struct parsed_cart cartridge;
        get_cart(&cartridge, argv[1]);
        printf("%s\n", cartridge.title);
    }
    
    return 0;
}