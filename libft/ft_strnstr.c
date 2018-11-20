/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:43:52 by majones           #+#    #+#             */
/*   Updated: 2018/06/10 00:46:42 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t		itn;
	char		*it1;
	char		*it2;

	if (!*need)
		return ((void *)hay);
	while (len-- && *hay)
	{
		if (*hay == *need)
		{
			itn = len;
			it1 = (void *)hay + 1;
			it2 = (void *)need + 1;
			while (itn-- && *it1 && *it2 && *it1 == *it2)
			{
				++it1;
				++it2;
			}
			if (!*it2)
				return ((void *)hay);
		}
		hay++;
	}
	return (NULL);
}
