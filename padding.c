#include "ft_ssl.h"

int        pad_check(unsigned long long len)
{
   unsigned long long a;

    a = 1;
    while (a * 512 < (len + 64 + 1))
        a += 1;
    return (a * 512 - len - 64 -1);
}

m_s       *padding(m_s *pre_image)
{
    unsigned long long padding;
    unsigned char new_length[128];
    unsigned long long bit_padding;
    unsigned int *hash_result;

    ft_bzero(new_length, 127);
    padding = pad_check(pre_image->bit_size);
    bit_padding = (pre_image->bit_size + 64 + 1 + padding);
    ft_memcpy(&new_length, ((pre_image->STREAMS) ? pre_image->stream : pre_image->input),\
     (pre_image->bit_size / 8));
    new_length[pre_image->bit_size / 8] = 0x80;
    ft_bzero(new_length + (pre_image->bit_size / 8) + 1, (padding / 8));
    ft_memcpy((new_length + (pre_image->bit_size / 8 + 1) + (padding / 8)), (unsigned long long *)&pre_image->bit_size, 8);
    printf("PADDING IS %llu\n", padding);
    printf("PRE_IMAGE BIT SIZE IS %llu\n", pre_image->bit_size);
    printf("BIT PADDING IS %llu\n", bit_padding);
    int b = -1;
    while (++b < 128)
        printf("%i:        %u\n",b, new_length[b]);
    pre_image->digest = (unsigned char*)ft_strnew(32);
    hash_result = (ft_strcmp("md5", pre_image->com) == 0) ?
    (unsigned int *)md5_hash(new_length, bit_padding) :
    (unsigned int *)sha256_hash(new_length, bit_padding);
    pre_image->digest = bytes2_nibl_2chr((unsigned char *)hash_result, pre_image->digest);
    int i = -1;
    printf("DIGEST: ");
    while (++i < 64)
        printf("%x", pre_image->digest[i]);
    printf("\n");
    return (pre_image);
}