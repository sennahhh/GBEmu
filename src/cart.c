#include <stdint.h>
#include <stdio.h>

struct parsed_cart_header {
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
    uint8_t global_checksum[2];
};

struct parsed_cart_header cart_header;
unsigned char full_cart_header[80];
unsigned char *full_rom;

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

const char* parse_license(uint8_t new_lic, uint8_t old_lic) {

if(old_lic == 0x33) {
    for(int i = 0; i < 61; i++) {
        //int num = (int)strtol(memcpy(), " ", 16);
    }
    
}

return "hej";
}

int parse_cart_header() {
    int i = 0;
    int j = 0;
    uint8_t new_lic_code[2];
    uint8_t old_lic_code;
    uint8_t cart_type_code;
    uint8_t rom_size_code;
    uint8_t ram_size_code;

    for(j = 0; j < 4; j++) {
        cart_header.entry_point[j] = full_cart_header[i];
        i++;
    }

    for(j = 0; j < 48; j++) {
        cart_header.nintendo_logo[j] = full_cart_header[i];
        i++;
    }

    for(j = 0; j < 16; j++) {
        cart_header.title[j] = full_cart_header[i];
        i++;
    }

    for(j = 0; j < 2; j++) {
        new_lic_code[j] = full_cart_header[i];
        i++;
    }
    
    cart_header.SGB_flag = full_cart_header[i];
    i++;

    cart_type_code = full_cart_header[i];
    i++;

    rom_size_code = full_cart_header[i];
    i++;

    ram_size_code = full_cart_header[i];
    i++;
    
    cart_header.dest_code = full_cart_header[i];
    i++;

    old_lic_code = full_cart_header[i];
    i++;

    cart_header.version_of_game = full_cart_header[i];
    i++;

    cart_header.header_checksum = full_cart_header[i];
    i++;

    for(j = 0; j < 2; j++) {
        cart_header.global_checksum[j] = full_cart_header[i];
        i++;
    }

    printf("%s", parse_license(old_lic_code, old_lic_code));

    return 0;
}


char *old_license_codes[] = {
    "00	None",
    "01	Nintendo",
    "08	Capcom",
    "09	Hot-B",
    "0A	Jaleco",
    "0B	Coconuts Japan",
    "0C	Elite Systems",
    "13	EA (Electronic Arts)",
    "18	Hudsonsoft",
    "19	ITC Entertainment",
    "1A	Yanoman",
    "1D	Japan Clary",
    "1F	Virgin Interactive",
    "24	PCM Complete",
    "25	San-X"
    "28	Kotobuki Systems",
    "29	Seta",
    "30	Infogrames",
    "31	Nintendo",
    "32	Bandai",
    "33	Indicates that the New licensee code should be used instead.",
    "34	Konami",
    "35	HectorSoft",
    "38	Capcom",
    "39	Banpresto",
    "3C	.Entertainment i",
    "3E	Gremlin",
    "41	Ubisoft",
    "42	Atlus",
    "44	Malibu",
    "46	Angel",
    "47	Spectrum Holoby",
    "49	Irem",
    "4A	Virgin Interactive",
    "4D	Malibu",
    "4F	U.S. Gold",
    "50	Absolute",
    "51	Acclaim",
    "52	Activision",
    "53	American Sammy",
    "54	GameTek",
    "55	Park Place",
    "56	LJN",
    "57	Matchbox",
    "59	Milton Bradley",
    "5A	Mindscape",
    "5B	Romstar",
    "5C	Naxat Soft",
    "5D	Tradewest",
    "60	Titus",
    "61	Virgin Interactive",
    "67	Ocean Interactive",
    "69	EA (Electronic Arts)",
    "6E	Elite Systems",
    "6F	Electro Brain",
    "70	Infogrames",
    "71	Interplay",
    "72	Broderbund",
    "73	Sculptered Soft",
    "75	The Sales Curve",
    "78	t.hq",
    "79	Accolade",
    "7A	Triffix Entertainment",
    "7C	Microprose",
    "7F	Kemco",
    "80	Misawa Entertainment",
    "83	Lozc",
    "86	Tokuma Shoten Intermedia",
    "8B	Bullet-Proof Software",
    "8C	Vic Tokai",
    "8E	Ape",
    "8F	I’Max",
    "91	Chunsoft Co.",
    "92	Video System",
    "93	Tsubaraya Productions Co.",
    "95	Varie Corporation",
    "96	Yonezawa/S’Pal",
    "97	Kaneko",
    "99	Arc",
    "9A	Nihon Bussan",
    "9B	Tecmo",
    "9C	Imagineer",
    "9D	Banpresto",
    "9F	Nova",
    "A1	Hori Electric",
    "A2	Bandai",
    "A4	Konami",
    "A6	Kawada",
    "A7	Takara",
    "A9	Technos Japan",
    "AA	Broderbund",
    "AC	Toei Animation",
    "AD	Toho",
    "AF	Namco",
    "B0	acclaim",
    "B1	ASCII or Nexsoft",
    "B2	Bandai",
    "B4	Square Enix",
    "B6	HAL Laboratory",
    "B7	SNK",
    "B9	Pony Canyon",
    "BA	Culture Brain",
    "BB	Sunsoft",
    "BD	Sony Imagesoft",
    "BF	Sammy",
    "C0	Taito",
    "C2	Kemco",
    "C3	Squaresoft",
    "C4	Tokuma Shoten Intermedia",
    "C5	Data East",
    "C6	Tonkinhouse",
    "C8	Koei",
    "C9	UFL",
    "CA	Ultra",
    "CB	Vap",
    "CC	Use Corporation",
    "CD	Meldac",
    "CE	.Pony Canyon or",
    "CF	Angel",
    "D0	Taito",
    "D1	Sofel",
    "D2	Quest",
    "D3	Sigma Enterprises",
    "D4	ASK Kodansha Co.",
    "D6	Naxat Soft",
    "D7	Copya System",
    "D9	Banpresto",
    "DA	Tomy",
    "DB	LJN",
    "DD	NCS",
    "DE	Human",
    "DF	Altron",
    "E0	Jaleco",
    "E1	Towa Chiki",
    "E2	Yutaka",
    "E3	Varie",
    "E5	Epcoh",
    "E7	Athena",
    "E8	Asmik ACE Entertainment",
    "E9	Natsume",
    "EA	King Records",
    "EB	Atlus",
    "EC	Epic/Sony Records",
    "EE	IGS",
    "F0	A Wave",
    "F3	Extreme Entertainment",
    "FF	LJN"
};

char *new_license_codes[] = {
    "00	None",
    "01	Nintendo R&D1",
    "08	Capcom",
    "13	Electronic Arts",
    "18	Hudson Soft",
    "19	b-ai",
    "20	kss",
    "22	pow",
    "24	PCM Complete",
    "25	san-x",
    "28	Kemco Japan",
    "29	seta",
    "30	Viacom",
    "31	Nintendo",
    "32	Bandai",
    "33	Ocean/Acclaim",
    "34	Konami",
    "35	Hector",
    "37	Taito",
    "38	Hudson",
    "39	Banpresto",
    "41	Ubi Soft",
    "42	Atlus",
    "44	Malibu",
    "46	angel",
    "47	Bullet-Proof",
    "49	irem",
    "50	Absolute",
    "51	Acclaim",
    "52	Activision",
    "53	American sammy",
    "54	Konami",
    "55	Hi tech entertainment",
    "56	LJN",
    "57	Matchbox",
    "58	Mattel",
    "59	Milton Bradley",
    "60	Titus",
    "61	Virgin",
    "64	LucasArts",
    "67	Ocean",
    "69	Electronic Arts",
    "70	Infogrames",
    "71	Interplay",
    "72	Broderbund",
    "73	sculptured",
    "75	sci",
    "78	THQ",
    "79	Accolade",
    "80	misawa",
    "83	lozc",
    "86	Tokuma Shoten Intermedia",
    "87	Tsukuda Original!",
    "91	Chunsoft",
    "92	Video system",
    "93	Ocean/Acclaim",
    "95	Varie",
    "96	Yonezawa/s’pal",
    "97	Kaneko",
    "99	Pack in soft",
    "A4	Konami (Yu-Gi-Oh!)"
};

char *cartridge_types[] = {
    "00	ROM ONLY",
    "01	MBC1",
    "02	MBC1+RAM",
    "03	MBC1+RAM+BATTERY",
    "05	MBC2",
    "06	MBC2+BATTERY",
    "08	ROM+RAM 1",
    "09	ROM+RAM+BATTERY 1",
    "0B	MMM01",
    "0C	MMM01+RAM",
    "0D	MMM01+RAM+BATTERY",
    "0F	MBC3+TIMER+BATTERY",
    "10	MBC3+TIMER+RAM+BATTERY 2",
    "11	MBC3",
    "12	MBC3+RAM 2",
    "13	MBC3+RAM+BATTERY 2",
    "19	MBC5"
    "1A	MBC5+RAM",
    "1B	MBC5+RAM+BATTERY",
    "1C	MBC5+RUMBLE",
    "1D	MBC5+RUMBLE+RAM",
    "1E	MBC5+RUMBLE+RAM+BATTERY",
    "20	MBC6",
    "22	MBC7+SENSOR+RUMBLE+RAM+BATTERY",
    "FC	POCKET CAMERA",
    "FD	BANDAI TAMA5",
    "FE	HuC3",
    "FF	HuC1+RAM+BATTERY"
};