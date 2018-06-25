/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:45:13 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/22 17:32:08 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char *s1, char *s2)
{
	int	i;

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

char		*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[0] &&
		ft_check((char *)haystack + i, (char *)needle) == 1)
			return ((char *)haystack + i);
		else
			i++;
	}
	return (NULL);
}
