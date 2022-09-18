#include <stdio.h>
#include <stdint.h>

void print_bytes(unsigned char *start_pointer, int length)
{
    int offset = 0;
    for(int offset = 0; offset < length; ++offset){
        printf("0x%02x ", *(start_pointer + offset));
    }
}

void print_header(unsigned char from, unsigned char to, int indent){
    for(;indent >=0; --indent){
        printf(" ");
    }

    for(;from <= to; from ++){
        printf("%2X   ", from);
    }
}

void hex_view_memory(void *start_pointer)
{
    unsigned char *start = (unsigned char*) (((intptr_t)start_pointer >> 4) << 4);
    unsigned char *last = (unsigned char*)start_pointer+32;
    unsigned char *current = start;

    printf("Start memory at: %p\n", start_pointer);
    print_header(0, 7, 23);
    print_header(8, 15, 8);
    printf("\n");


    for(; current <= last; current+=16){
        printf("%8p \t\t", current);
        
        print_bytes(current, 8);
        printf("         ");
        print_bytes(current+8, 8);

        printf("\n");    
    }

}