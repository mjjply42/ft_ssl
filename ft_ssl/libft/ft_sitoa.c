/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 06:21:32 by majones           #+#    #+#             */
/*   Updated: 2018/09/13 06:21:46 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sitoa(intmax_t n)
{
	char			*str;
	unsigned int	size;
	uintmax_t		num;

	num = n * (n < 0 ? -1 : 1);
	size = 1 + (n < 0);
	while (num >= 10)
	{
		size++;
		num /= 10;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
		str[0] = '-';
	num = n * (n < 0 ? -1 : 1);
	while (size-- > (n < 0))
	{
		str[size] = '0' + (num % 10);
		num = num / 10;
	}
	return (str);
}
