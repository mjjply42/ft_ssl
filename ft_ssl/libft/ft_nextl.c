#include "libft.h"

char	*ft_nextl(char *str, char c)
{
	while (*str && *str != c)
		str++;
	return (str);
}