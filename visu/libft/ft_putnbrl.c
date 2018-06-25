/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:28:32 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/29 17:02:28 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrl(long nb)
{
	long	pwr;
	long	tmp;

	tmp = nb;
	if ((pwr = nb < 0 ? -1 : 1) == -1)
		ft_putchar('-');
	while (tmp /= 10)
		pwr *= 10;
	while (pwr)
	{
		ft_putchar((nb / pwr) + '0');
		nb -= (nb / pwr) * pwr;
		pwr /= 10;
	}
}
