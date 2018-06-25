/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:39:02 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/03/06 15:42:08 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countword(const char *str, char sep)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			cnt++;
			while (str[i] && str[i] != sep)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}
