#include "libft.h"

void	ft_putintarr(int *arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
		ft_putnbr(arr[i++]);
}