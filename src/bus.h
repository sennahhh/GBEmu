#ifndef BUS_H
#define BUS_H
#include <stdint.h>

uint8_t bus_read(uint16_t);

void bus_write(uint16_t, uint8_t);

#endif