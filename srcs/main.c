/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:29:32 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/25 12:42:35 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

int			main(void)
{
	t_map	map;
	t_piece	piece;
	char	*line;

	//map = malloc(sizeof(t_map));
	//piece = malloc(sizeof(t_piece));
	map.grid = NULL;
	piece.block = NULL;
	if (get_next_line(0, &line) != 1)
		return (0);
	map.pl = line[10] == '1' ? 'O' : 'X';
	free(line);
	while (1)
	{
		if (!get_map(&map))
			return (0);
		if (!get_piece(&piece))
			return (0);
		if (!put_piece(&map, &piece))
			return (0);
		//else
			//printf("%d %d\n", piece.y, piece.x);
	}
	return (0);
}
