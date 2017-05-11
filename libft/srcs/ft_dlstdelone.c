/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:58:23 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/06 14:15:58 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*prev;
	t_dlist	*next;

	prev = (*alst)->prev;
	next = (*alst)->next;
	prev->next = next;
	next->prev = prev;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = prev;
}
