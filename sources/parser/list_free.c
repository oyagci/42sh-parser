/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:42:20 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 14:50:54 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			list_free(union u_node *content)
{
	t_nlist	*l;
	t_list	*next;

	l = &content->list;
	while (l->andlst)
	{
		next = l->andlst->next;
		ptree_free((t_ptree **)&l->andlst->content);
		free(l->andlst);
		l->andlst = next;
	}
}
