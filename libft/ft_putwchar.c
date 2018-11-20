#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	write(1, &c, 1);
}