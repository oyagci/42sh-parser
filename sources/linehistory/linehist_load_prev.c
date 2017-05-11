/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linehist_load_prev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 14:42:33 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/27 12:26:47 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linehistory/linehistory.h>
#include <libft.h>

void			linehist_load_prev(t_line *l)
{
	t_linehist	*prevline;

	if ((prevline = linehist_get_prevline()))
		linehist_copy_line(l, prevline);
}
