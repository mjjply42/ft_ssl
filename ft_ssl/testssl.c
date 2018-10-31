#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <stdbool.h>
#include "ft_ssl.h"

void    md5_hash(unsigned char *message, ULL byte_count)
{
    h_s *hash;
    hash = (h_s*)ft_memalloc(sizeof(h_s));
    ULL bits_done;
    bits_done = 0;
    t_mem *message;
    message = NULL;

    while (bits_done < (byte_count / 8))
   { 
        printf("%s\n", message);
        ft_char_to_uint32(hash->message, message + bits_done, 16);
        printf("Values are %x\n%x\n%x\n%x\n", hash->message[0], hash->message[1], hash->message[2], hash->message[3]);
        hash_md5(hash);
        printf("%llx\n", hash->state[0]);
        printf("%llx\n", hash->state[1]);
        printf("%llx\n", hash->state[2]);
        printf("%llx\n", hash->state[3]);
        ft_uint32_to_chr(digest, *hash->state + bits_done, 16);
        printf("Message Digest Value is %c\n", digest[0]);
        bits_done += (512 / 8);
   }//u7dfeliurfdfdw427
    //7d4a6e80b726435ee6b8232b360262eb
}

int     md5_start(m_s *pre_image/*, char **argv*/)
{
    int i;

    i = 0;
    
    if (pre_image->stream != NULL)
    {
        printf("STREAM is %s\n", pre_image->stream);
        pre_image->bit_size = (ft_strlen(pre_image->stream) * 8);
        printf("Padding is %llu\n", pre_image->bit_size);
        padding(pre_image);
        //DUMP ALL STREAM DATA AFTER PASSING THROUGH
    }
    if (pre_image->input != NULL)
    {
        printf("INPUT is %s\n", pre_image->input);
        pre_image->bit_size = (ft_strlen(pre_image->input) * 8);
        padding(pre_image);
    }
    //destroy_data(pre_image);
   
    return (pre_image->count);
}