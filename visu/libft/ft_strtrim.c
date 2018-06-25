/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:38:25 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/29 17:25:38 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int	len;

	if (s != NULL)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		if (!*s)
			return (ft_strnew(0));
		len = ft_strlen(s);
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			len--;
		return (ft_strsub(s, 0, len));
	}
	return (NULL);
}
