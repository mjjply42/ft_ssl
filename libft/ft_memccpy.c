/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:08:51 by majones           #+#    #+#             */
/*   Updated: 2018/06/11 10:07:38 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*ptr;
	unsigned const char		*s;

	ptr = (unsigned char*)dst;
	s = (unsigned const char*)src;
	while (n--)
	{
		*ptr = *s;
		if (*s == (unsigned char)c)
			return (++ptr);
		ptr++;
		s++;
	}
	return (NULL);
}
