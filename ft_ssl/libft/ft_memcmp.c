/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:16:26 by majones           #+#    #+#             */
/*   Updated: 2018/06/10 00:50:08 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char		*ptr1;
	unsigned const char		*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	while (n-- != 0)
	{
		if (*ptr1 == *ptr2)
		{
			ptr1++;
			ptr2++;
		}
		else
			return (*ptr1 - *ptr2);
	}
	return (0);
}
