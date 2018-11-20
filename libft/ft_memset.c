/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:53:56 by majones           #+#    #+#             */
/*   Updated: 2018/06/11 09:48:55 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memset(void *str, int x, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char *)str;
	while (len--)
	{
		ptr[len] = (unsigned char)x;
	}
	return (str);
}
