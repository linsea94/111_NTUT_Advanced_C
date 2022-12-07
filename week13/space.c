#include "space.h"

//SMALL_ELEMENT_SIZE(32)*NUM_SMALL_BYTE_BUF(8)
unsigned char buffer[SMALL_ELEMENT_SIZE*NUM_SMALL_BYTE_BUF];

unsigned char byte_small_buf_mask = 0;


void print_buffer_status (void)
{
    int i;
    unsigned char mask = 0x80;
  
    printf ("      byte_small_buf_mask: ");
    for (i = 0; i< NUM_SMALL_BYTE_BUF; i++)
    {
        printf ("%d ", (byte_small_buf_mask & mask) >> (7-i));
        mask = mask >> 1;
    }

    printf ("\n");
}

void  our_malloc(int type, void **target, int *mem_location)
{
    int location;

    if (byte_small_buf_mask == SMALL_FULL){
        return;
    }
    else if (type == TYPE_SMALL)
    {
        unsigned char test_bit = 1;
        location = test_single_location(1, NUM_SMALL_BYTE_BUF);
        set_single_bit(&test_bit, location);
        *target = buffer + (SMALL_ELEMENT_SIZE * location);
        *mem_location = location;
    }
    else
    {
        location = test_dual_location(3, NUM_SMALL_BYTE_BUF);
        if (location >= 0)
        {
            unsigned char test_bit = 3;
            set_dual_bit(&test_bit, location);
            *target = buffer + (SMALL_ELEMENT_SIZE * location);
            *mem_location = location;
        }
        else
        {
            return;
        }
    }    
}

int test_single_location(int mask, int mask_length)
{
    int i;

    for (i = 0; i< mask_length; i++)
    {
        if (!(mask & byte_small_buf_mask))
        {
            return i;
        }
        else
        {
            mask = mask << 1;
        }
    }
}

void set_single_bit(unsigned char *mask, int location)
{
    byte_small_buf_mask = byte_small_buf_mask | (*mask<<location);
}

int test_dual_location(int mask, int mask_length)
{
    int i;

    for (i = 0; i< mask_length-1; i++)
    {
        if ((mask & byte_small_buf_mask)==0)
        {
            
            return i;
        }
        else
        {
            mask = mask << 1;
        }
    }
    printf("dual return -1");
    return -1;
}

void set_dual_bit(unsigned char *mask, int location)
{
    byte_small_buf_mask = byte_small_buf_mask | (*mask<<location);
}

void clear_single_bit(unsigned char *mask, int location)
{
    byte_small_buf_mask = byte_small_buf_mask & ~(*mask<<location);
}

void clear_dual_bit(unsigned char *mask, int location)
{
    printf("dual mask %d\n", *mask);
    byte_small_buf_mask = byte_small_buf_mask & ~(*mask<<location);
}

void  our_free(int type, int mem_location)
{
    printf("del mem_location %d\n",mem_location);
    if (type == TYPE_SMALL)
    {
        printf("del type small\n");
        unsigned char clear_bit = 1;
        clear_single_bit(&clear_bit, mem_location);
    }
    else if (type == TYPE_LARGE)
    {
        printf("del type large\n");
        unsigned char clear_bit = 3;
        clear_dual_bit(&clear_bit, mem_location);
    }
}
