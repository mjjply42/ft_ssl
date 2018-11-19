#include "ft_ssl.h"
unsigned char    *md5_hash(unsigned char *message, unsigned long long byte_count)
{
    h_s *hash;
    unsigned long long bits_done;
    uint32_t state[4];
    char *str;
    
    hash = ft_memalloc(sizeof(h_s));
    bits_done = 0;
    state[0] = 0x67452301;
    state[1] = 0xefcdab89;
    state[2] = 0x98badcfe;
    state[3] = 0x10325476;
    while (bits_done < (byte_count / 8))
   { 
        ft_char_to_uint32(hash->message, message + bits_done, sizeof(unsigned long long) * 16);
        md5_process(hash, state);
        ft_uint32_to_chr((unsigned char*)hash->message, (uint32_t*)(message + bits_done) , sizeof(unsigned long long) * 16);
        bits_done += (512 / 8);
   }
   free(hash);
    str = ft_strnew(16);
   return (ft_uint32_to_chr((unsigned char *)str, state, sizeof(unsigned long long) * 4));
}

int     md5_pad_start(m_s *pre_image, char **argv)
{
    printf("%i\n", pre_image->flags[1]);
    printf("INPUT %s\n", pre_image->input);
    if (pre_image->STREAMS != FALSE)
    {
        pre_image->bit_size = (ft_strlen(pre_image->stream) * 8);
        printf("HEL\n");
        padding(pre_image);
        printf("HELLOOO\n");
        print_digest(pre_image->digest, pre_image, argv);
        pre_image->STREAMS = pre_image->bit_size = 0;
        //free(pre_image->stream);
    }
    if (pre_image->input != NULL)
    {
        printf("dasfdghjjk");
        pre_image->bit_size = (ft_strlen(pre_image->input) * 8);
        printf("HERE\n");
        printf("BIT SIZE %llu\n", pre_image->bit_size);
        padding(pre_image);
        print_digest(pre_image->digest, pre_image, argv);
        //pre_image->input = NULL;
    }
    if (pre_image->s_error == TRUE)
        error_code(3);
    //destroy_data(pre_image);
    return (pre_image->count);
}


/*TEST

int     md5_pad_start(m_s *pre_image, char **argv)
{
    int i;
//
// MAKE SUR YOU TAKE CARE OF THE 'CONSTANT -R' NEEDED ACROSS HASH VALUES. -R VALUE REMAINS FOR EVERY INSTANCE,
// UNLESS -Q IS ACTED UPON IT
//
    i = pre_image->count;
    //printf("ARGV IS %s\n", *(argv + pre_image->count));
    if (ft_strcmp("-p", argv[2]) == 0)
    {
        pre_image->flags[0] = 1;
        pre_image->STREAMS = TRUE;
    }
    printf("%i\n", pre_image->flags[1]);
    //printf("!STREAMS %s\n", pre_image->stream);
    if (pre_image->STREAMS != FALSE || pre_image->flags[0] == 1)
    {
        pre_image->bit_size = (ft_strlen(pre_image->stream) * 8);
        //printf("HEL\n");
        padding(pre_image);
        //printf("HELLOOO\n");
        print_digest(pre_image->digest, pre_image, argv);
        pre_image->STREAMS = pre_image->bit_size = 0;
        //free(pre_image->stream);
    }
    if (pre_image->input != NULL)
    {
        pre_image->bit_size = (ft_strlen(pre_image->input) * 8);
        //printf("HERE\n");
        //printf("BIT SIZE %llu\n", pre_image->bit_size);
        padding(pre_image);
        print_digest(pre_image->digest, pre_image, argv);
        ///pre_image->input = NULL;
    }
    if (pre_image->s_error == TRUE)
        error_code(3);
    //destroy_data(pre_image);
    return (i += 1);
}*/