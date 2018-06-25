/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:54:23 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/25 16:26:08 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	free_block(t_piece *piece)
{
	int		i;

	if (piece->block != NULL)
	{
		i = 0;
		while (i < piece->r_height)
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
		return (NULL);
	i = 0;
	while (i < height)
	{
	//	dprintf(2, "malloc de grid[%d][%d]\n", i, j);
		if (!(block[i] = (char *)malloc(sizeof(char) * (width + 1))))
			return (NULL);
		if (get_next_line(0, &line) != 1)
			return (NULL);
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
/*
static void	trim_values(t_piece *piece)
{
	int		i;
	int		j;

	piece->height = 0;
	piece->width = 0;
	i = piece->r_height - 1;
	while (i > 0)
	{
		j = piece->r_width - 1;
		while (j > 0)
		{
			if (piece->block[i][j] == '*')
			{
				if (j > piece->width)
					piece->width = j;
				if (i > piece->height)
					piece->height = i;
			}
			j--;
		}
		i--;
	}
//	dprintf(2, "r_height = %d || r_width = %d\nheight = %d || width = %d\n", piece->r_height, piece->r_width, piece->height, piece->width);
}*/

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
//	trim_values(piece);
	return (1);
}
