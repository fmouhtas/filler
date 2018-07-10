/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:54:23 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/07/10 11:08:50 by fmouhtas         ###   ########.fr       */
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
		return (NULL);
	i = 0;
	while (i < height)
	{
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

static void	get_bounds(t_piece *piece)
{
	int		x;
	int		y;

	piece->up = piece->height;
	piece->left = piece->width;
	piece->right = 0;
	piece->bottom = 0;
	y = 0;
	while (y < piece->height)
	{
		x = 0;
		while (x < piece->width)
		{
			if (piece->block[y][x] == '*')
			{
				if (y < piece->up)
					piece->up = y;
				if (x < piece->left)
					piece->left = x;
				if (y > piece->bottom)
					piece->bottom = y;
				if (x > piece->right)
					piece->right = x;
			}
			x++;
		}
		y++;
	}
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
	get_bounds(piece);
	return (1);
}
