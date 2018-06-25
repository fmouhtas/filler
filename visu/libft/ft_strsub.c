/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:12:58 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/28 11:19:12 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		if (!(out = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len && s[start + i])
		{
			out[i] = s[start + i];
			i++;
		}
		out[i] = '\0';
		return (out);
	}
	return (NULL);
}
