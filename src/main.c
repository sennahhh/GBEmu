#include <stdio.h>
#include <stdlib.h>
#include "emu.h"
#include "cart.h"


int main(int argc, char **argv) {
    
    if(argc >= 2) {
        struct parsed_cart cart = get_cart(argv[1]);
    }
    
    return 0;
}