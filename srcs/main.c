/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:29:32 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/28 12:43:54 by fmouhtas         ###   ########.fr       */
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
	map.en = map.pl == 'O' ? 'X' : 'O';
	free(line);
	while (1)
	{
		if (!get_map(&map))
			return (0);
		if (!get_piece(&piece))
			return (0);
		if (!put_piece(&map, &piece))
		{
			ft_putstr("0 0\n");
			return (0);
		}
		else
		{
			ft_putnbr(piece.y);
			ft_putchar(' ');
			ft_putnbr(piece.x);
			ft_putchar('\n');
		}
	}
	return (0);
}
