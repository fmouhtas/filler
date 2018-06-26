/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:52:47 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/26 15:08:41 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		skip_line(int fd, int n)
{
	char	*line;

	while (n > 0)
	{
		if (get_next_line(fd, &line) != 1)
			return (0);
		if (line)
			free(line);
		n--;
	}
	return (1);
}
