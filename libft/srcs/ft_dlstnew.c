/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:54:45 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/06 14:14:31 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dlist			*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist		*lst;

	lst = (t_dlist *)ft_memalloc(sizeof(t_dlist));
	if (content && content_size)
	{
		lst->content = ft_memalloc(content_size);
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	return (lst);
}
