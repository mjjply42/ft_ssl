/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 05:28:28 by majones           #+#    #+#             */
/*   Updated: 2018/09/13 06:20:59 by majones          ###   ########.fr       */
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

char	*ft_itoa_base(unsigned int n, int base)
{
	char			*str;
	unsigned int	size;
	unsigned int	num;

	num = n;
	size = 1;
	while (num >= (unsigned int)base)
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
