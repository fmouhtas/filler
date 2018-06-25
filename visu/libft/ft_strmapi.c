/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:42:53 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/28 11:13:52 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*out;

	if (s != NULL && f != NULL)
	{
		i = 0;
		out = ft_strdup(s);
		while (out && out[i])
		{
			out[i] = f(i, s[i]);
			i++;
		}
		return (out);
	}
	return (NULL);
}
