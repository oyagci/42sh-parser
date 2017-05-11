/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linehist_load_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 14:42:59 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/27 12:27:08 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linehistory/linehistory.h>
#include <libft.h>

void			linehist_load_next(t_line *l)
{
	t_linehist	*nextline;

	if ((nextline = linehist_get_nextline()))
		linehist_copy_line(l, nextline);
	else
	{
		ft_strclr(l->content);
		l->index = 0;
		l->len = 0;
	}
}
