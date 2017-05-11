/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:48:37 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/06 13:48:50 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t			ft_dlstcount(t_dlist *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i += 1;
		lst = lst->next;
	}
	return (i);
}
