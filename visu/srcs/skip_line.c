/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:52:47 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/25 17:54:25 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		skip_line(int n)
{
	char	*line;

	while (n > 0)
	{
		if (get_next_line(1, &line) != 1)
			return (0);
		if (line)
			free(line);
		n--;
	}
	return (1);
}
