/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:29:46 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/26 19:29:08 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	draw_square(t_env *env, int x, int y, char c)
{
	int		xx;
	int		yy;
	int		col;

	if (c == 'O')
		col = 0x66ccff;
	else if (c == 'o')
		col = 0x66aaff;
	else if (c == 'X')
		col = 0xf17662;
	else if (c == 'x')
		col = 0xf11862;
	else
		col = 0xd5c6ae;
	y *= ZOOM;
	x *= ZOOM;
	yy = 0;
	while (yy < ZOOM)
	{
		xx= 0;
		while (xx < ZOOM)
		{
			mlx_pixel_put(env->mlx, env->win, x + xx, y + yy, col);
			xx++;
		}
		yy++;
	}
}

static int	skip_piece(t_env *env)
{
	char	*line;
	int		n;

	if (get_next_line(0, &line) != 1)
		return (0);
	n = ft_atoi(line + 6);
	//	printf("n = %d\n", n);
	free(line);
	skip_line(0, n);
	while (1)
	{
		if (get_next_line(0, &line) != 1)
			return (0);
		if (*line == ' ')
		{
			free(line);
			return (1);
		}
		if (*line == '=')
		{
			n = ft_atoi(line + 9);
			mlx_string_put(env->mlx, env->win, 10, 10, 0x000000, "P1: ");
			mlx_string_put(env->mlx, env->win, 50, 10, 0x000000, ft_itoa(n));
			free(line);
			if (get_next_line(0, &line) != 1)
				return (0);
			n = ft_atoi(line + 9);
			mlx_string_put(env->mlx, env->win, 10, 50, 0x000000, "P2: ");
			mlx_string_put(env->mlx, env->win, 50, 50, 0x000000, ft_itoa(n));
			free(line);
			env->done = 1;
			return (1);
		}
		free(line);
	}
	return (1);
}

static int	draw_map(t_env *env)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < env->height)
	{
		//printf("%d ", i);
		if (get_next_line(0, &line) != 1)
			return (1);
		//printf("%s\n", line);
		j = 0;
		while (j < env->width)
		{
			draw_square(env, i, j, line[j + 4]);
			j++;
		}
		free(line);
		i++;
	}
	if (!skip_piece(env))
		return (0);
	return (1);
}

static int	get_size(t_env *env)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) != 1)
		return (0);
	i = 8;
	env->height = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	env->width = ft_atoi(line + i);
	free(line);
	printf("%d / %d\n", env->height, env->width);
	return (1);
}

int		main(void)
{
	t_env	env;

	env.done = 0;
	skip_line(0, 9);
	get_size(&env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.height * ZOOM, env.width * ZOOM, "VISU FILLER");
	if (!env.done)
		mlx_loop_hook(env.mlx, draw_map, &env);
	else
		mlx_string_put(env.mlx, env.win, ZOOM / 2, ZOOM / 2, 0xffffff, "DONE!");
	mlx_loop(env.mlx);
	return (0);
}
