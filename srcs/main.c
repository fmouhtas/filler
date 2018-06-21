/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:29:32 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/21 18:13:01 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

int			main(void)
{
	t_map	map;
	t_piece	piece;
	char	*line;

	map.grid = NULL;
	piece.block = NULL;
	if (get_next_line(0, &line) != 1)
		return (0);
	map.pl = line[10] == '1' ? '0' : 'X';
	free(line);
	while (1)
	{
		dprintf(2, "GET MAP\n");
		if (!get_map(&map))
			return (0);
		dprintf(2, "GET PIECE\n");
		if (!get_piece(&piece))
			return (0);
		dprintf(2, "PUT PIECE\n");
		if (!put_piece(&map, &piece))
			return (0);
	}
	return (0);
}
