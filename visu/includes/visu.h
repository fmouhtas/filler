/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:30:24 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/26 19:36:37 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>

# define ZOOM	12

typedef struct	s_env
{
	void		*mlx;
	void		*win;

	int			done;
	int			width;
	int			height;
}				t_env;

int				skip_line(int fd, int n);

#endif
