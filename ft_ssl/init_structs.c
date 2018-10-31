#include "ft_ssl.h"

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
    return (message);
}

void	ft_free_mem(t_mem *mem)
{
	free(mem->data);
	free(mem);
}

void		init_mem(t_mem *mem)
{
	mem->h[0] = 0x6a09e667;
	mem->h[1] = 0xbb67ae85;
	mem->h[2] = 0x3c6ef372;
	mem->h[3] = 0xa54ff53a;
	mem->h[4] = 0x510e527f;
	mem->h[5] = 0x9b05688c;
	mem->h[6] = 0x1f83d9ab;
	mem->h[7] = 0x5be0cd19;
}