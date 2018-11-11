#include "libft.h"

unsigned char      *bytes2_nibl_2chr(unsigned char *before, unsigned char *after)
{
    int a;
    int b;

    a = 0;
    b = 0;
    while (a < 32)
    {
        after[a] = ((before[b] & 0xf0) >> 4);
        after[a + 1] = (before[b] & 0x0f);
        a += 2;
        b++;
    }
    return (after);
}