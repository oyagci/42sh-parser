/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linehist_get_prevline.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:26:58 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/26 17:04:13 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linehistory/linehistory.h>
#include <libft.h>

extern t_list	*g_history;
extern size_t	g_current_index;
extern size_t	g_max_index;

t_linehist		*linehist_get_prevline(void)
{
	t_list	*head;
	size_t	i;

	i = 0;
	head = g_history;
	while (head && i < g_current_index && i < g_max_index)
	{
		i += 1;
		head = head->next;
	}
	if (head)
	{
		g_current_index += (g_current_index < g_max_index ? 1 : 0);
		return (head->content);
	}
	return (NULL);
}
