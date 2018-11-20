#include "libft.h"

char	*ft_nextspace(char *str)
{
	while (*str && *str != ' ')
		str++;
	return (str);
}
