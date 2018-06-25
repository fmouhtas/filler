/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:30:24 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/25 18:12:33 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

# define WIN_H		600;
# define WIN_W		800;

typedef struct	s_env
{
	void		*mlx;
	void		*win;

	int			width;
	int			height;
}				t_env;

int				skip_line(int n);

#endif
