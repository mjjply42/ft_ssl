#include "ft_ssl.h"

/*int       sha256_pad_start(m_s *pre_image, char **argv)
{
    int i;

    i = pre_image->count;
    //printf("ARGV IS %s\n", *(argv + pre_image->count));
    if (ft_strcmp("-p", argv[2]) == 0)
        pre_image->flags[0] = pre_image->STREAMS = 1;
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