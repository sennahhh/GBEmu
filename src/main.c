#include <stdio.h>
#include <stdlib.h>
#include "emu.h"
#include "cart.h"


int main(int argc, char **argv) {
    
    if(argc >= 2) {
        printf("%d first\n", read_cart_header(argv[1]));
        printf("%d second\n", parse_cart_header());
    }
    
    return 0;
}