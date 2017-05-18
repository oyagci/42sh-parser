/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:00:14 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 11:21:38 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <libft.h>

/*
** Returns a token list made from a token array
*/

t_list			*get_tlst(t_token *tarr, size_t sz)
{
	t_list	*lst = NULL;
	t_list	*elem = NULL;
	size_t	i = 0;

	while (i < sz)
	{
		elem = ft_lstnew(NULL, 0);
		elem->content = tarr + i;
		ft_lstpush(&lst, elem);
		i += 1;
	}
	return (lst);
}

