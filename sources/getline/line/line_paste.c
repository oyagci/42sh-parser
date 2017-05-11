/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_paste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:40:51 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 13:38:19 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>
#include <libft.h>

extern char		*g_buffer;

static void		insert_buffer(t_line *line, char *content, size_t sz)
{
	char	*start;

	start = line->content + line->index;
	ft_memmove(start + sz, start, ft_strlen(start) + 1);
	ft_memmove(start, content, sz);
	line->index += sz;
}

void			line_paste(t_line *line)
{
	size_t	buf_sz;

	if (g_buffer)
	{
		buf_sz = ft_strlen(g_buffer);
		line->len += buf_sz;
		line_grow_if_needed(line);
		insert_buffer(line, g_buffer, buf_sz);
	}
}
