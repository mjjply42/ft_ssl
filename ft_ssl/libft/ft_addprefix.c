#include "libft.h"

char	*ft_addprefix(char *pre, char *str)
{
	char *tmp;

	tmp = ft_strjoin(pre, str);
	free(str);
	return (tmp);
}