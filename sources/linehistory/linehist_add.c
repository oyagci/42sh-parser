/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linehist_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 14:12:15 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/26 15:47:42 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linehistory/linehistory.h>
#include <libft.h>

t_list			*g_history;
size_t			g_current_index;
size_t			g_max_index;

void			linehist_add(char *command)
{
	t_linehist	*linehist;
	t_list		*elem;

	if (!(linehist = ft_memalloc(sizeof(t_linehist))))
		return ;
	linehist->value = ft_strdup(command);
	linehist->index = ++g_max_index;
	elem = ft_lstnew(NULL, 0);
	elem->content = linehist;
	ft_lstadd(&g_history, elem);
}
