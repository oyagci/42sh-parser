/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_grow_if_needed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:59:44 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 12:54:39 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>
#include <libft.h>

int				line_grow_if_needed(t_line *l)
{
	char	*tmp;

	while (l->len >= l->max_len)
	{
		if ((tmp = ft_strnew(l->max_len + 255)) == NULL)
			return (-1);
		ft_strcpy(tmp, l->content);
		ft_strdel(&l->content);
		l->content = tmp;
		l->max_len += 255;
	}
	return (1);
}
