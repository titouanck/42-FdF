/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:30:06 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/15 15:24:58 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_bufferList	*ftlst_new_buffer(void)
{
	t_bufferList	*new;

	new = malloc(sizeof(t_bufferList));
	if (!new)
		return (NULL);
	new->content = malloc(BUFFER_SIZE + 1);
	if (!(new->content))
		return (free(new), NULL);
	(new->content)[0] = '\0';
	new->next = 0;
	return (new);
}

t_fdList	*ftlst_new_fd(int fd)
{
	t_fdList	*new;

	new = malloc(sizeof(t_fdList));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->begin = ftlst_new_buffer();
	if (!(new->begin))
		return (free(new), NULL);
	new->next_fd = 0;
	return (new);
}

int	end_of_line(char *content)
{
	size_t	i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	count_memory(t_bufferList *current)
{
	size_t	memory;
	size_t	i;

	memory = 1;
	while (current)
	{
		i = 0;
		while ((current->content)[i])
		{
			memory++;
			i++;
			if ((current->content)[i - 1] == '\n')
				break ;
		}
		if (i > 0 && (current->content)[i - 1] == '\n')
		{
			i++;
			break ;
		}
		current = current->next;
	}
	return (memory);
}

t_fdList	*clean_fd_list(t_fdList *fd_list, t_fdList *c_fd)
{
	t_fdList	*tmp;

	if (!((c_fd->begin->content)[0]))
	{
		free(c_fd->begin->content);
		free(c_fd->begin);
		if (fd_list == c_fd)
			fd_list = fd_list->next_fd;
		else
		{
			tmp = fd_list;
			while (tmp->next_fd && tmp->next_fd != c_fd)
				tmp = tmp->next_fd;
			if (tmp->next_fd)
				tmp->next_fd = tmp->next_fd->next_fd;
		}
		free(c_fd);
	}
	return (fd_list);
}
