/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:43:29 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/17 13:16:20 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

t_ptree			*list_new(void)
{
	t_ptree		*node;

	node = NULL;
	if ((node = ft_memalloc(sizeof(t_ptree))))
	{
		node->type = NT_LIST;
		if ((node->content.list = ft_memalloc(sizeof(t_nlist))) == NULL)
		{
			del_node(node);
			return (NULL);
		}
	}
	return (node);
}

void			list_del(t_nlist *l)
{
	del_node(l->list);
	del_node(l->and_or);
	free(l);
}

t_ptree			*list(t_parser *p)
{
	t_ptree	*node;

	node = NULL;
	if ((node = list_new()))
	{
		if ((node->content.list->and_or = and_or(p)) == NULL)
		{
			del_node(node);
			return (NULL);
		}
	}
	return (node);
}
