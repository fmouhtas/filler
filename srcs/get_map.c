/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:35:25 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/21 18:31:45 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	create_map(t_map *map)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	i = 8;
	map->height = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	map->width = ft_atoi(line + i);
	free(line);
	if (!(map->grid = (char **)malloc(sizeof(char *) * map->height)))
		return (0);
	i = 0;
	while (i < map->height)
		if (!(map->grid[i++] = (char *)malloc(sizeof(char) * map->width + 1)))
			return (0);
	skip_line(1);
	return (1);
}

static int	copy_map(t_map *map)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < map->height)
	{
		get_next_line(0, &line);
		j = 0;
		while (j < map->width)
		{
			map->grid[i][j] = line[j + 4];
			j++;
		}
		map->grid[i][j] = '\0';
		free(line);
		i++;
	}
	return (1);
}

int			get_map(t_map *map)
{
	if (map->grid == NULL)
	{
		if (!create_map(map))
			return (0);
	}
	else
		skip_line(2);
	copy_map(map);
	return (1);
}
