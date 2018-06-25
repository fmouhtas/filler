/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:09:41 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/25 16:34:49 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	can_fit(t_map *map, t_piece *piece)
{
	int		touch;
	int		i;
	int		j;
	char	c;

	touch = 0;
	i = 0;
	while (i < piece->height)
	{
		j = 0;
		while (j < piece->width)
		{
			if (piece->block[i][j] == '*')
			{
				c = map->grid[piece->y + i][piece->x + j];
				if (c == map->en)
					return (0);
				if (c == map->pl)
					touch++;
			}
			j++;
		}
		i++;
	}
	return (touch == 1 ? 1 : 0);
}

int			put_piece(t_map *map, t_piece *piece)
{
	piece->y = 0;
	while (piece->y + piece->height < map->height)
	{
		piece->x = 0;
		while (piece->x + piece->width < map->width)
		{
			if (can_fit(map, piece))
			{
			//	dprintf(2, "\n\nCAN FIT : pos = %d %d\n", piece->y, piece->x);
				return (1);
			}
			piece->x++;
		}
		piece->y++;
	}
	return (0);
}
