#include "ft_ssl.h"
void    bit_play(unsigned char *new_length)
{
    uint32_t *pre_message;

    pre_message = (uint32_t*)malloc(32);
    printf("3HERE\n");
    ft_char_to_uint32(pre_message, new_length, sizeof(unsigned long long) * 32);
    printf("ERTYUI %#x\n", pre_message[14]);
    int l = -1;
    while (++l < 32)
        pre_message[l] = swap_byte_uint((unsigned int)pre_message[l]);
    printf("DFGHJK %#x\n", pre_message[14]);
    ft_bzero(new_length, 127);
    ft_uint32_to_chr(new_length, pre_message, sizeof(unsigned long long) * 32);
}

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
    unsigned long long z;
 
    ft_bzero(new_length, 127);
    padding = pad_check(pre_image->bit_size);
    bit_padding = (pre_image->bit_size + 64 + 1 + padding);
    ft_memcpy(&new_length, ((pre_image->STREAMS) ? pre_image->stream : pre_image->input),\
     (pre_image->bit_size / 8));
    new_length[pre_image->bit_size / 8] = 0x80;
    ft_bzero(new_length + (pre_image->bit_size / 8) + 1, (padding / 8));
    //bigchar_32bit_swap(new_length);
    //printf("NEW_LENGTH contents %s\n", new_length);
    //turn from char to uint32
    //turn from uint32 to char
    //u64_u32_swap(pre_image);
    bit_play(new_length);
    z = ((pre_image->bit_size >> 32) | (pre_image->bit_size << 32));
    printf("AFTER %#llx", z);
    ft_memcpy((new_length + (pre_image->bit_size / 8 + 1) + (padding / 8)), (unsigned long long *)&z, 8);
    //ft_memcpy((new_length + (pre_image->bit_size / 8 + 1) + (padding / 8)), (unsigned long long *)&pre_image->bit_size, 8);
    
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