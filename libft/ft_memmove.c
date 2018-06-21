/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:06:14 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/27 15:56:10 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst < src)
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	else if (dst > src)
	{
		while (len--)
			*((char *)dst + len) = *((char *)src + len);
	}
	return (dst);
}
