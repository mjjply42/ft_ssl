#include "libft.h"

unsigned int swap_byte_uint(unsigned int a)
{
    unsigned int b;

    b = (((a & 0xFF) << 24)
        | ((a & 0xFF00) << 8)
        | ((a & 0xFF0000) >> 8)
        | ((a & 0xFF000000) >> 24));
    return (b);
}