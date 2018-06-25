/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:19:58 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/27 17:59:56 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;

	out = NULL;
	if (lst)
	{
		out = ft_lstnew(lst->content, lst->content_size);
		out = f(lst);
		out->next = ft_lstmap(lst->next, f);
	}
	return (out);
}
