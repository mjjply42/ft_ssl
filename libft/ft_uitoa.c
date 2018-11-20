/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 05:35:21 by majones           #+#    #+#             */
/*   Updated: 2018/09/14 20:35:09 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(uintmax_t n)
{
	char			*str;
	unsigned int	size;
	uintmax_t		num;

	size = 1;
	num = n;
	while (num >= 10)
	{
		size++;
		num /= 10;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size--)
	{
		str[size] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}
