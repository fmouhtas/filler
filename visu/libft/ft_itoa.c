/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:17:28 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/22 17:26:55 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		set_neg(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	else
		return (0);
}

static int		set_len(int n, int neg)
{
	long	pow;
	int		len;

	pow = 1;
	len = 1 + neg;
	while (pow * 10 <= n)
	{
		pow *= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*out;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = set_neg(&n);
	len = set_len(n, neg);
	if (!(out = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	out[len--] = '\0';
	if (neg == 1)
		out[0] = '-';
	while (len >= neg)
	{
		out[len--] = ((n % 10) + 48);
		n /= 10;
	}
	return (out);
}
