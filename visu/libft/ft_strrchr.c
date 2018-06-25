/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:23:00 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/27 14:36:21 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (i >= 0)
	{
		if (*((char *)(s + i)) == c)
			return ((char *)(s + i));
		else
			i--;
	}
	return (NULL);
}
