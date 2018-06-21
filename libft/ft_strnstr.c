/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:12:50 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/22 17:26:01 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

char			*ft_strnstr(const char *haystack, const char *needle, \
				size_t len)
{
	size_t	i;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0] &&
		ft_check((char *)haystack + i, (char *)needle) == 1)
		{
			if (i + ft_strlen(needle) > len)
				return (NULL);
			else
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
