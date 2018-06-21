/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:45:36 by fmouhtas          #+#    #+#             */
/*   Updated: 2017/11/30 10:39:49 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*out;

	if (!(out = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		out->content = NULL;
		out->content_size = 0;
		out->next = NULL;
		return (out);
	}
	if (!(out->content = (void *)malloc(content_size)))
		return (NULL);
	ft_memcpy(out->content, content, content_size);
	out->content_size = content_size;
	out->next = NULL;
	return (out);
}
