/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_addchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:07:06 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 15:46:49 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <getline/getline.h>

int				line_addchar(unsigned char *buffer, t_line *l)
{
	if (line_grow_if_needed(l) == -1)
		return (-1);
	ft_memmove(l->content + l->index + 1, l->content + l->index,
			ft_strlen(l->content + l->index) + 1);
	*(l->content + l->index) = *buffer;
	l->index += 1;
	l->len += 1;
	return (0);
}
