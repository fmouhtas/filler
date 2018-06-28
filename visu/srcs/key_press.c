/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:40:44 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/28 15:25:10 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			key_press(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key == 49)
		env->play = env->play == 1 ? 0: 1;
//	printf("key = %d\n", key);
	return (0);
}