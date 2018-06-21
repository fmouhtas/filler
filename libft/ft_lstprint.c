/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:11:34 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/30 08:51:00 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	int		n;

	n = 0;
	while (lst)
	{
		ft_putstr("\nLink: ");
		ft_putnbr(n++);
		ft_putstr("\nAddress: ");
		ft_putaddress(lst);
		ft_putstr("\nContent: ");
		write(1, lst->content, lst->content_size);
		ft_putstr("\nContent size: ");
		ft_putnbr(lst->content_size);
		ft_putstr("\nNext: ");
		ft_putaddress(lst->next);
		lst = lst->next;
	}
	ft_putstr("\n*END*\n");
}
