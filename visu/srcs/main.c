/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:29:46 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/26 09:48:02 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int	draw_map(t_env *env)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < env->height)
	{
		if (get_next_line(1, &line) != 1)
			return (1);
		j = 0;
		while (j < env->width)
		{
			draw_square(env, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

static int	get_size(t_env *env)
{
	char	*line;
	int		i;

	if (get_next_line(1, &line) != 1)
		return (0);
	i = 8;
	env->height = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	env->width = ft_atoi(line + i);
	free(line);
	return (1);
}

int		main(void)
{
	t_env	env;
	
	env.mlx = mlx_init();
	skip_line(9);
	get_size(&env);
	env.win = mlx_new_window(env.mlx, env.width * 5, env.height * 5, "VISU FILLER");
	while (1)
	{
		draw_map(&env);
	}
}
