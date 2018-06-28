/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:29:46 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/28 17:06:07 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	ft_put_pixel(t_env *env, int x, int y, int col)
{
	if (x >= 0 && x < env->win_width && y >= 0 && y < env->win_height)
		*(int *)&env->data[(y * env->line_size) + (x * env->bpp / 8)] = col;
}

static void	draw_square(t_env *env, int x, int y, char c)
{
	int		xx;
	int		yy;
	int		col;

	if (c == 'O')
		col = COL_O;
	else if (c == 'o')
		col = COL_SO;
	else if (c == 'X')
		col = COL_X;
	else if (c == 'x')
		col = COL_SX;
	else
		col = COL_BK;
	y *= ZOOM;
	x *= ZOOM;
	yy = 0;
	while (yy < ZOOM)
	{
		xx= 0;
		while (xx < ZOOM)
		{
			ft_put_pixel(env, x + xx, y + yy, col);
			xx++;
		}
		yy++;
	}
}


static int	draw_map(t_env *env)
{
	int		i;
	int		j;
	char	*line;
	if ((env->play == 1 || env->play == -1) && !env->done)
	{
		env->img = mlx_new_image(env->mlx, env->win_width, env->win_height);
		env->data = mlx_get_data_addr(env->img, &env->bpp, &env->line_size, &env->endian);
		i = 0;
		while (i < env->map_height)
		{
			//printf("%d ", i);
			if (get_next_line(0, &line) != 1)
				return (1);
			//printf("%s\n", line);
			j = 0;
			while (j < env->map_width)
			{
				draw_square(env, j, i, line[j + 4]);
				j++;
			}
			free(line);
			i++;
		}
		if (!skip_piece(env))
			return (0);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		mlx_destroy_image(env->mlx, env->img);
		if (env->play == -1)
			env->play = 0;
	}
	else if (env->done)
	{
		mlx_string_put(env->mlx, env->win, 150, env->win_height + 10, COL_O, ft_itoa(env->one.score));
		mlx_string_put(env->mlx, env->win, 150, env->win_height + 30, COL_X, ft_itoa(env->two.score));
	}
	mlx_string_put(env->mlx, env->win, 10, env->win_height + 10, COL_O, env->one.name);
	mlx_string_put(env->mlx, env->win, 10, env->win_height + 30, COL_X, env->two.name);
	return (1);
}

int		main(void)
{
	t_env	env;

	env.done = 0;
	env.play = -1;
	skip_line(0, 6);
	get_player_name(&env);
	get_size(&env);
	env.win_width = env.map_width * ZOOM;
	env.win_height = env.map_height * ZOOM;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.win_width, env.win_height + 60, "VISU FILLER");
	env.bpp = 16;
	env.line_size = env.win_width * env.bpp;
	env.endian = 0;
	draw_map(&env);
	mlx_loop_hook(env.mlx, draw_map, &env);
	mlx_key_hook(env.win, key_press, &env);
	mlx_loop(env.mlx);
	return (0);
}
