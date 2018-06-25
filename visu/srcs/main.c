/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:29:46 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/25 18:12:19 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

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
	return (1);
}

int		main(void)
{
	t_env	env;
	
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 600, 800, "VISU FILLER");
	skip_line(9);
	get_size(&env);
	while (1)
	{
		if (!get_size(&env))
			return (0);
	}
}
