#include "libft.h"

int		*ft_strtointarr(char *str)
{
	int		*arr;
	int		wc;
	int		i;

	wc = ft_wordcount(str);
	arr = (int *)malloc(sizeof(int) * wc);
	str = ft_nextword(str);
	i = 0;
	while (i < wc)
	{
		arr[i++] = atoi(str);
		str = ft_nextspace(str);
		str = ft_nextword(str);
	}
	return (arr);
}