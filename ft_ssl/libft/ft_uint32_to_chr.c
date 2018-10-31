#include "libft.h"
#include <stdio.h>

unsigned char	*ft_uint32_to_chr(unsigned char *output \
	, unsigned long long *input , unsigned int len)
{
	unsigned int i;
	unsigned int j;
	printf("HERE");
	i = 0;
	j = 0;
	while (j < len)
	{
		printf("HERE");
		output[j] = ((unsigned char)input[i] & 0xff);
		output[j + 1] = ((unsigned char)(input[i] >> 8));
		output[j + 2] = ((unsigned char)(input[i] >> 16));
		output[j + 3] = ((unsigned char)(input[i] >> 24));
		i += 1;
		j += 4;
	}
	return (output);
}