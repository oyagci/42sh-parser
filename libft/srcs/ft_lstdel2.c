/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:36:13 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 15:36:59 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_lstdel2(t_list **alst, void (*del)(void *))
{
	t_list	*next;

	while (*alst)
	{
		next = (*alst)->next;
		del((*alst)->content);
		free(*alst);
		*alst = next;
	}
	*alst = NULL;
}
