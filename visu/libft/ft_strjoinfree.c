/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:32:33 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/02/14 14:35:09 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2, char ctl)
{
	char		*out;

	if (!(out = ft_strjoin(s1, s2)))
		return (NULL);
	if (ctl == 'L' || ctl == 'B')
		free(s1);
	if (ctl == 'R' || ctl == 'B')
		free(s2);
	return (out);
}
