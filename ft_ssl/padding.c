#include "ft_ssl.h"

/*int        pad_check(ULL len)
{
   ULL a;

    a = 1;
    printf("LEN is %llu\n", len);
    while (a * 512 < (len + 64 + 1))
        a += 1;
    return (a * 512 - len - 64 -1);
}

void       padding(ULL pre_pad_size, m_s *pre_image)
{
    ULL padding;
    unsigned char *new_length;
    ULL bit_padding;

    padding = pad_check(pre_pad_size);
    printf("Padding is %llu\n", padding);
    bit_padding =  (pre_pad_size + 64 + 1 + padding);
    new_length = (unsigned char*)ft_strnew( sizeof(unsigned char) * 64);
    ft_memcpy(new_length, ((pre_image->STREAMS) ? pre_image->stream : pre_image->input),\
     (pre_pad_size / 8));
    new_length[pre_pad_size / 8] = 0x80;
    ft_memset(new_length + (pre_pad_size / 8), 0, (padding / 8));
    ft_memcpy(new_length + (pre_pad_size / 8) + (padding / 8), &pre_pad_size, sizeof(ULL));
    md5_hash(new_length, bit_padding);
}*/