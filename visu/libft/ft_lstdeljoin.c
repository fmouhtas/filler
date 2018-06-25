/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeljoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:50:56 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/02/13 15:51:07 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdeljoin(t_list **al, t_list *del)
{
	t_list	*tmp;

	tmp = *al;
	if (tmp == del)
	{
		*al = (*al)->next;
		free(tmp->content);
		free(tmp);
		return ;
	}
	while (tmp->next != del)
		tmp = tmp->next;
	tmp->next = del->next;
	free(del->content);
	free(del);
}
