/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linehist_copy_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:15:47 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/27 12:20:05 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linehistory/linehistory.h>
#include <libft.h>

void			linehist_copy_line(t_line *l, t_linehist *histline)
{
	size_t len;

	len = ft_strlen(histline->value);
	l->len = len;
	line_grow_if_needed(l);
	ft_strcpy(l->content, histline->value);
	l->index = len;
}
