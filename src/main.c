#include <stdio.h>
#include <stdlib.h>
#include "emu.h"
#include "cart.h"


int main(int argc, char **argv) {
    
    if(argc >= 2) {
        printf("%d first\n", get_cart(argv[1]));
        printf("%s", cartridge.title);
    }
    
    return 0;
}