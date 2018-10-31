/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 05:30:27 by majones           #+#    #+#             */
/*   Updated: 2018/09/13 05:34:24 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	get_digit(int num)
{
	if (num < 10)
		return ('0' + num);
	else
		return ('a' + num - 10);
}

char	*ft_uitoa_base(uintmax_t n, int base)
{
	char			*str;
	unsigned int	size;
	uintmax_t	num;

	num = n;
	size = 1;
	while (num >= (uintmax_t)base)
	{
		size++;
		num /= base;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	num = n;
	while (size--)
	{
		str[size] = get_digit(num % base);
		num = num / base;
	}
	return (str);
}
