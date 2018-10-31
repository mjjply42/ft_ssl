#include "libft.h"

wchar_t	*ft_wstrcpy(wchar_t *dst, const wchar_t *src)
{
	size_t	i;

	i = -1;
	while (*(src + ++i))
		*(dst + i) = *(src + i);
	*(dst + i) = '\0';
	return (dst);
}