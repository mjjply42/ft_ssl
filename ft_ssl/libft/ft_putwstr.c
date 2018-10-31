#include "libft.h"

void	ft_putwstr(wchar_t const *s)
{
	while (*s)
		ft_putwchar(*(s++));
}