#include <stdio.h>
#include <stdint.h>

// 0000	3FFF	16 KiB ROM bank 00	From cartridge, usually a fixed bank
// 4000	7FFF	16 KiB ROM Bank 01~NN	From cartridge, switchable bank via mapper (if any)
// 8000	9FFF	8 KiB Video RAM (VRAM)	In CGB mode, switchable bank 0/1
// A000	BFFF	8 KiB External RAM	From cartridge, switchable bank if any
// C000	CFFF	4 KiB Work RAM (WRAM)	
// D000	DFFF	4 KiB Work RAM (WRAM)	In CGB mode, switchable bank 1~7
// E000	FDFF	Mirror of C000~DDFF (ECHO RAM)	Nintendo says use of this area is prohibited.
// FE00	FE9F	Sprite attribute table (OAM)	
// FEA0	FEFF	Not Usable	Nintendo says use of this area is prohibited
// FF00	FF7F	I/O Registers	
// FF80	FFFE	High RAM (HRAM)	
// FFFF	FFFF	Interrupt Enable register (IE)	

uint8_t 
bus_read(uint16_t addr) 
{
    if(addr <= 0x8000) 
    {
        return read_cart(addr);
    } 
    else if(addr < 0xA000) 
    {
        return read_VRAM(addr);
    } 
    else if(addr < 0xC000) 
    {
        return read_cart(addr);
    }
    else if(addr < 0xE000)
    {
        return read_WRAM(addr);
    }
    else if(addr < 0xFE00)
    {
        return 0;
    }
    else if(addr < 0xFEA0) 
    {
        return read_OAM(addr);
    }
    else if(addr < 0xFF00)
    {
        return 0;
    }
    else if(addr < 0xFF80)
    {
        return read_IO(addr);
    }
    else if(addr < 0xFFFF)
    {
        return read_HRAM(addr);
    }
    else if(addr == 0xFFFF)
    {
        return read_IE_reg();
    }
    return 0;
}

void
bus_write(uint16_t addr, uint8_t byte)
{
    if(addr <= 0x8000) 
    {
        cart_write(addr, byte);
    } 
    else if(addr < 0xA000) 
    {
        write_VRAM(addr, byte);
    } 
    else if(addr < 0xC000) 
    {
        write_cart(addr, byte);
    }
     else if(addr < 0xE000)
    {
        write_WRAM(addr, byte);
    }
    else if(addr < 0xFE00)
    {
        // echo ram not writable
    }
    else if(addr < 0xFEA0) 
    {
        write_OAM(addr, byte);
    }
    else if(addr < 0xFF00)
    {
        // not usable
    }
    else if(addr < 0xFF80)
    {
        write_IO(addr, byte);
    }
    else if(addr < 0xFFFF)
    {
        write_HRAM(addr, byte);
    }
    else if(addr == 0xFFFF)
    {
        set_IE_reg();
    }
}