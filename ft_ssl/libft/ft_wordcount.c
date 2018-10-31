#include "libft.h"

int		ft_wordcount(char *str)
{
	int		wc;

	wc = 0;
	str = ft_nextword(str);
	while (*str)
	{
		wc++;
		str = ft_nextspace(str);
		str = ft_nextword(str);
	}
	return (wc);
}
