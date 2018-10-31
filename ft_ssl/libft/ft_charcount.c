/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:35:31 by majones           #+#    #+#             */
/*   Updated: 2018/08/12 14:19:36 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t		ft_charcount(const char *str)
{
	size_t count;
	size_t i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '\t' && str[i] <= '~')
			count++;
		i++;
	}
	return (count);
}
