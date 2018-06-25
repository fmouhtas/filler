/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:01:23 by fmouhtas          #+#    #+#             */
/*   Updated: 2018/06/25 11:49:52 by fmouhtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	send_line(t_list **l, char **line, t_list **first)
{
	int		i;
	char	*tmp;

	i = 0;
	while (((char *)(*l)->content)[i] && ((char *)(*l)->content)[i] != '\n')
		i++;
	if (!(*line = ft_strsub((char *)(*l)->content, 0, i)))
		return (0);
	i += ((char *)(*l)->content)[i] == '\n' ? 1 : 0;
	if (((char *)(*l)->content)[i])
	{
		if (!(tmp = ft_strdup((char *)(*l)->content + i)))
			return (0);
		free((*l)->content);
		(*l)->content = tmp;
	}
	else
		ft_lstdeljoin(first, *l);
	*l = *first;
	return (1);
}

static int	find_fd(t_list **l, int fd, t_list **first)
{
	*first = *l;
	while (*l && (int)(*l)->content_size != fd)
		*l = (*l)->next;
	if (!*l)
	{
		if (!(*l = (t_list *)malloc(sizeof(t_list))))
			return (0);
		(*l)->content_size = fd;
		if (!((*l)->content = ft_strdup("")))
			return (0);
		(*l)->next = *first;
		*first = *l;
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*l = NULL;
	t_list			*first;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!find_fd(&l, fd, &first))
		return (-1);
	while (!ft_strchr((char *)l->content, '\n')
			&& (ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!(l->content = ft_strjoinfree((char *)l->content, buff, 'L')))
			return (-1);
	}
	if (l && ((char *)l->content)[0])
	{
		if (!send_line(&l, line, &first))
			return (-1);
		return (1);
	}
	l = first;
	return (ret ? 1 : 0);
}
