/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:43:29 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/17 15:38:20 by oyagci           ###   ########.fr       */
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

int				list_add_andor(t_parser *p, t_ptree *node)
{
	t_ptree	*andor;
	t_list	*elem;

	if ((andor = and_or(p)) == NULL)
		return (0);
	elem = ft_lstnew(NULL, 0);
	elem->content = andor;
	ft_lstpush(&node->content.and_or->and_or, elem);
	return (1);
}

t_ptree			*list(t_parser *p)
{
	t_ptree	*node;

	node = NULL;
	if ((node = list_new()))
	{
		if (list_add_andor(p, node) == 0)
		{
			del_node(node);
			return (NULL);
		}
		while (1)
		{
			if (!parser_expect(p, T_SEMICOL))
				break ;
			list_add_andor(p, node);
		}
	}
	return (node);
}
