/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linehist_get_nextline.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:48:44 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/26 17:25:37 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linehistory/linehistory.h>
#include <libft.h>

extern t_list	*g_history;
extern size_t	g_current_index;
extern size_t	g_max_index;

t_linehist		*get_elem(size_t index)
{
	t_list	*head;
	size_t	i;

	i = 0;
	head = g_history;
	while (head && i < index && i < g_max_index)
	{
		i += 1;
		head = head->next;
	}
	if (head)
		return (head->content);
	return (NULL);
}

t_linehist		*linehist_get_nextline(void)
{
	t_linehist	*next;

	next = 0;
	if (g_current_index > 0)
	{
		g_current_index -= 1;
		next = get_elem(g_current_index - 1);
	}
	else
		return (NULL);
	return (next);
}
