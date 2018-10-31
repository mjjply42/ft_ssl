#include "libft.h"

uint32_t	*ft_char_to_uint32(uint32_t *output
	, unsigned char *input
	, unsigned int len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (j < len)
	{
		output[i] = ((uint32_t)input[j])
			| (((uint32_t)input[j + 1]) << 8)
			| (((uint32_t)input[j + 2]) << 16)
			| (((uint32_t)input[j + 3]) << 24);
		i += 1;
		j += 4;
	}
	return (output);
}