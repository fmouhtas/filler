/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:57:14 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/28 10:57:38 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t i;
	size_t len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		i = 0;
		while (i < len)
			s[i++] = '\0';
	}
}