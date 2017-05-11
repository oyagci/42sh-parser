/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:09:57 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/23 14:08:47 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

char			*get_chunk(char *s)
{
	char	*chunk;
	char	*newline;

	newline = ft_strchr(s, '\n');
	if (newline)
		chunk = ft_strsub(s, 0, (newline - s));
	else
		chunk = ft_strdup(s);
	return (chunk);
}

void			remove_chunk(char **s)
{
	char	*newline;

	newline = ft_strchr(*s, '\n');
	if (newline != NULL)
		ft_memmove(*s, newline + 1, ft_strlen(newline));
	else
		ft_strclr(*s);
}

int				get_next_line(int fd, char **line)
{
	static char	*content[128] = { NULL };
	char		buffer[BUFF_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || fd > 128)
		return (-1);
	(content[fd] == NULL) ? (content[fd] = ft_strnew(0)) : 0;
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if ((content[fd] = ft_stradd(content[fd], buffer)) == NULL)
			return (-1);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret == -1)
		return (-1);
	if (!(*line = get_chunk(content[fd])))
		return (-1);
	if (ft_strlen(content[fd]) == 0 || ret == 0)
		return (0);
	remove_chunk(&content[fd]);
	return (1);
}
