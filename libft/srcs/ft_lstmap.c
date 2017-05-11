/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:30:21 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/09 13:59:22 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first_elem;

	new = NULL;
	first_elem = NULL;
	if (lst != NULL)
	{
		if (!(new = f(lst)))
			return (NULL);
		first_elem = new;
		lst = lst->next;
		while (lst != NULL)
		{
			new->next = f(lst);
			new = new->next;
			lst = lst->next;
		}
		new->next = NULL;
	}
	return (first_elem);
}
