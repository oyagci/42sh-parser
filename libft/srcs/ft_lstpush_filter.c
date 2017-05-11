/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_filter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:17:17 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/05 10:45:51 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush_filter(t_list *lst, void *content, size_t content_size,
		int (*f)(t_list *, void *, size_t))
{
	t_list	*lst_new;
	t_list	*tmp;
	t_list	*p_lst;

	if (lst == NULL)
		return (0);
	tmp = NULL;
	p_lst = lst;
	while (p_lst != NULL && f(p_lst, content, content_size) < 0)
	{
		tmp = p_lst;
		p_lst = p_lst->next;
	}
	if (!(lst_new = ft_lstnew(content, content_size)))
		return (NULL);
	lst_new->next = p_lst;
	if (tmp != NULL)
		tmp->next = lst_new;
	else
		lst = lst_new;
	return (lst);
}
