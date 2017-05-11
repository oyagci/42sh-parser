/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:57:31 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 12:42:25 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>
#include <libft.h>

char	*g_buffer;

void			line_copy(t_line *line)
{
	(void)line;
	if (g_buffer)
		ft_strdel(&g_buffer);
	g_buffer = ft_strdup(line->content);
}
