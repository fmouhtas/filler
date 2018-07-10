/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:09:41 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/07/10 11:08:48 by fmouhtas         ###   ########.fr       */
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
	i = piece->start.y;
	while (i < piece->height - piece->end.y)
	{
		j = 0;
		while (j < piece->width)
		{
			if (piece->block[i][j] == '*')
			{
				if (piece->pos.y + i < 0 || piece->pos.y + i >= map->height)
					return (0);
				if (piece->pos.x + j < 0 || piece->pos.x + j >= map->width)
					return (0);
				c = map->grid[piece->pos.y + i][piece->pos.x + j];
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
	piece->pos.y = -piece->start.y;
	while (piece->pos.y < map->height - piece->end.y)
	{
		piece->pos.x = 0;
		while (piece->pos.x < map->width - )
		{
			if (can_fit(map, piece))
			{
			//	dprintf(2, "\n\nCAN FIT : pos = %d %d\n", piece->y, piece->x);
				return (1);
			}
			piece->pos.x++;
		}
		piece->pos.y++;
	}
	return (0);
}
