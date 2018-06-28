/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:50:04 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/28 16:59:07 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			skip_line(int fd, int n)
{
	char	*line;

	while (n > 0)
	{
		if (get_next_line(fd, &line) != 1)
			return (0);
		if (line)
			free(line);
		n--;
	}
	return (1);
}

int			skip_piece(t_env *env)
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
			env->one.score = ft_atoi(line + 9);
			/*printf("%s\n", line);
			mlx_string_put(env->mlx, env->win, 10, 10, 0x000000, "P1: ");*/
			free(line);
			if (get_next_line(0, &line) != 1)
				return (0);
			env->two.score = ft_atoi(line + 9);
			/*mlx_string_put(env->mlx, env->win, 10, 50, 0x000000, "P2: ");*/
			free(line);
			env->done = 1;
			return (1);
		}
		free(line);
	}
	return (1);
}
