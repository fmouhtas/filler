/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:44:00 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/28 16:58:10 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int	get_name(t_player *pl)
{
	char	*line;
	int		start;
	int		end;
	int		i;

	if (get_next_line(0, &line) != 1)
		return (0);
	end = ft_strlen(line) - 1;
	while (line[end] != '.')
		end--;
	start = end;
	while (line[start - 1] != '/')
		start--;
	if (!(pl->name = (char *)malloc(sizeof(char) * (end - start) + 1)))
		return (0);
	i = 0;
	while (start < end)
		pl->name[i++] = line[start++];
	pl->name[i] = '\0';
	free(line);
	return (1);
}

int			get_player_name(t_env *env)
{
	if (!get_name(&env->one))
		return (0);
	skip_line(0, 1);
	if (!get_name(&env->two))
		return (0);
	printf("p1 = %s, p2 = %s\n", env->one.name, env->two.name);
	return (1);
}

int			get_size(t_env *env)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) != 1)
		return (0);
	i = 8;
	env->map_height = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	env->map_width = ft_atoi(line + i);
	free(line);
	return (1);
}
