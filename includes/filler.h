/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:24:32 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/21 17:08:50 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

# include <stdio.h>

typedef struct	s_piece
{
	int			height;
	int			width;
	int			x;
	int			y;
	char		**block;
}				t_piece;

typedef struct	s_map
{
	char		pl;
	int			height;
	int			width;
	char		**grid;
}				t_map;

int				get_map(t_map *map);
int				get_piece(t_piece *piece);
int				put_piece(t_map *map, t_piece *piece);
int				skip_line(int n);

#endif
