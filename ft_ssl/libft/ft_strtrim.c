/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 19:32:22 by majones           #+#    #+#             */
/*   Updated: 2018/05/30 15:05:26 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		end;
	int		i;

	end = 0;
	s = ft_nextword((char *)s);
	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			i++;
		end = i - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
	}
	(str = (char *)malloc(sizeof(char) * (end + 2)));
	if (!str)
		return (NULL);
	str[end + 1] = '\0';
	while (end-- >= 0)
		str[end + 1] = s[end + 1];
	return (str);
}
