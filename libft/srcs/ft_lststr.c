/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:16:14 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/10 14:17:04 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			**ft_lststr(t_list *lst)
{
	char			**arr;
	size_t const	sz = ft_lstcount(lst);
	size_t			i;

	arr = (char **)ft_memalloc(sizeof(char *) * (sz + 1));
	i = 0;
	while (lst && i < sz)
	{
		arr[i] = ft_strdup(lst->content);
		i += 1;
		lst = lst->next;
	}
	return (arr);
}
