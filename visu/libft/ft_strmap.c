/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:42:15 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/28 11:08:01 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new;

	if (s != NULL && f != NULL)
	{
		i = 0;
		new = ft_strdup(s);
		while (new && new[i])
		{
			new[i] = f(s[i]);
			i++;
		}
		return (new);
	}
	return (NULL);
}
