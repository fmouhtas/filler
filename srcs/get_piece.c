/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:54:23 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/21 18:07:19 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	free_block(t_piece *piece)
{
	int		i;

	if (piece->block != NULL)
	{
		i = 0;
		while (i < piece->height)
			free(piece->block[i++]);
		free(piece->block);
	}
}

static char	**get_block(int height, int width)
{
	int		i;
	int		j;
	char	*line;
	char	**block;

	if (!(block = (char **)malloc(sizeof(char *) * height)))
		return (0);
	i = 0;
	while (i < height)
	{
	//	dprintf(2, "malloc de grid[%d][%d]\n", i, j);
		if (!(block[i] = (char *)malloc(sizeof(char) * (width + 1))))
			return (0);
		get_next_line(0, &line);
		j = 0;
		while (j < width)
		{
			block[i][j] = line[j];
			j++;
		}
		block[i][j] = '\0';
		free(line);
		i++;
	}
	return (block);
}

int			get_piece(t_piece *piece)
{
	char	*line;
	int		i;

	free_block(piece);
	get_next_line(0, &line);
	i = 6;
	piece->height = ft_atoi(line + i);
	while (line[i++] != ' ');
	piece->width = ft_atoi(line + i);
	free(line);
	if (!(piece->block = get_block(piece->height, piece->width)))
		return (0);
	piece->x = 0;
	piece->y = 0;
	return (1);
}
