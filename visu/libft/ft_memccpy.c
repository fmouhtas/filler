/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:34:20 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/22 18:52:46 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*tmp_dst;
	char	*tmp_src;

	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	i = 0;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if ((unsigned char)tmp_src[i] == (unsigned char)c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
