/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 21:55:29 by majones           #+#    #+#             */
/*   Updated: 2018/06/11 10:56:34 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	size;
	unsigned int	num;

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
