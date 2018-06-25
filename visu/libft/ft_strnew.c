/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:43:11 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/16 12:50:43 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size + 1)
		new[i++] = '\0';
	return (new);
}
