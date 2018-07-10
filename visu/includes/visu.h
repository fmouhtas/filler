/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:30:24 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/07/09 18:03:49 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "../minilibx_macos/mlx.h"
# include "../../libft/libft.h"
# include <stdio.h>

# define ZOOM	12
# define COL_O	0x66ccff
# define COL_SO	0x66aaff
# define COL_X	0xf17662
# define COL_SX	0xf11862
# define COL_BK	0xd5c6ae

typedef struct	s_player
{
	char		*name;
	int			score;
}				t_player;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*data;
	int			bpp;
	int			line_size;
	int			endian;

	int			win_width;
	int			win_height;
	int			done;
	int			play;
	int			map_width;
	int			map_height;
	t_player	one;
	t_player	two;
}				t_env;

int				get_player_name(t_env *env);
int				get_size(t_env *env);
int				key_press(int key, t_env *env);
int				skip_line(int fd, int n);
int				skip_piece(t_env *env);

#endif
