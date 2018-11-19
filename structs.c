#include "ft_ssl.h"
l_s        *init_start_data()
{
    l_s *message;

    message = (l_s*)malloc(sizeof(l_s));
    if (message == NULL)
        return (NULL);
    message->input = NULL;
    message->stream = NULL;
    message->file_name = NULL;
    message->FILES = FALSE;
    message->count = 0;
    return (message);
}
m_s        *init_message_data()
{
    m_s *message;

    message = (m_s*)malloc(sizeof(m_s));
    if (message == NULL)
        return (NULL);
    message->input = NULL;
    message->bit_size = 0;
    message->FILES = FALSE;
    message->stream= NULL;
    message->STREAMS = FALSE;
    ft_memset(message->flags, 0, 4);
    message->digest = ft_memset((unsigned char*)ft_strnew(32), 0, 32);
    message->file_name = NULL;
    return (message);
}

void        destroy_data(m_s *pre_image)
{
    //ft_memset(pre_image->digest, 0, 32);
    pre_image->flags[0] = 0;
    pre_image->flags[2] = 0;
    pre_image->flags[3] = 0;
    pre_image->bit_size = 0;
    pre_image->FILES = FALSE;
}