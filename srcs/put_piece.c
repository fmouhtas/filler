/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:09:41 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/25 12:30:12 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	can_fit(t_map *map, t_piece *piece)
{
	int		touch;
	int		i;
	int		j;

	touch = 0;
	i = 0;
	while (i < piece->height)
	{
		j = 0;
		while (j < piece->width)
		{
			touch += map->grid[piece->y + i][piece->x + j] == map->pl && piece->block[i][j] == '*';
			j++;
		}
		i++;
	}
	return (touch == 1 ? 1 : 0);
}

int			put_piece(t_map *map, t_piece *piece)
{
	piece->y = 0;
	while (piece->y < map->height - piece->height)
	{
		piece->x = 0;
		while (piece->x < map->width - piece->width)
		{
			if (can_fit(map, piece))
			{
				//printf("%d %d\n", piece->y, piece->x);
				dprintf(2, "CAN FIT : pos = %d %d\n", piece->y, piece->x);
				printf("%d %d\n", piece->y, piece->x);
				return (1);
			}
			piece->x++;
		}
		piece->y++;
	}
	return (0);
}
