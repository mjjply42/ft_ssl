#include "libft.h"
#include <stdio.h>

unsigned char	*ft_uint32_to_chr(unsigned char *output
	, uint32_t *input , unsigned int len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (j < len)
	{
		output[j] = ((unsigned char)input[i] & 0xff);
		//printf("OUTPUT %c\n%s\n", *output, output);
		output[j + 1] = ((unsigned char)(input[i] >> 8) & 0xff);
		output[j + 2] = ((unsigned char)(input[i] >> 16) & 0xff);
		output[j + 3] = ((unsigned char)(input[i] >> 24) & 0xff);
		i += 1;
		j += 4;
	}
	//printf("OUTPUT IS %x\n", output);
	return (output);
}