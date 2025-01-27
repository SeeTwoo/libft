/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:05:08 by walter            #+#    #+#             */
/*   Updated: 2025/01/27 10:22:39 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*build_line(t_gnllist *head)
{
	char	*line;
	char	*walker;

	line = malloc(sizeof(char) * (line_size(head) + 1));
	if (!line)
		return (NULL);
	walker = line;
	while (head)
	{
		ft_memcpy(walker, head->chunk, head->chunk_len);
		walker += head->chunk_len; 
		head = head->next;
	}
	*walker = '\0';
	return (line);
}

void	gnl_build_node(t_gnllist **head, t_gnllist **tail, char *buffer, int len)
{
	if (!(*head))
	{
		*head = gnl_new_node(buffer, len);
		*tail = (*head);
	}
	else
	{
		(*tail)->next = gnl_new_node(buffer, len);
		*tail = (*tail)->next;
	}
}

int	get_chunk(t_gnllist **head, t_gnllist **tail, char *buffer, int fd)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (bytes_read);
	buffer[bytes_read] = '\0';
	gnl_build_node(head, tail, buffer, bytes_read);
	return (bytes_read);
}

t_gnllist	*build_list(char *buffer, t_gnllist **head, t_gnllist **tail, int fd)
{
	int		bytes_read;

	if (buffer[0])
	{
		buffer_shift(buffer);
		gnl_build_node(head, tail, buffer, nl_ft_strlen(buffer));
		if (!(*head))
			return (NULL);
	}
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (ft_strchr(buffer, '\n'))
		{
			(*tail)->chunk_len = nl_ft_strlen(buffer);
			return (*head);
		}
		bytes_read = get_chunk(head, tail, buffer, fd);
		if (!tail || bytes_read < 0)
			return (gnl_free_list(*head));
	}
	return (*head);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	char		*line;
	t_gnllist	*head;
	t_gnllist	*tail;

	if (fd == -1)
		return (NULL);
	head = NULL;
	tail = NULL;
	head = build_list(buffer, &head, &tail, fd);
	if (!head)
		return (NULL);
	line = NULL;
	line = build_line(head);
	gnl_free_list(head);
	return (line);
}
