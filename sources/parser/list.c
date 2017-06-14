/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:43:29 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/14 14:06:37 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

int				add_to_list(t_parser *p, t_ptree *node)
{
	t_list	*elem;
	t_ptree	*andor;

	if ((elem = ft_lstnew(NULL, 0)))
	{
		if ((andor = and_or(p)) && andor != (void *)ERR_SYNTAX)
		{
			elem->content = andor;
			ft_lstpush(&node->content->list.andlst, elem);
			return (1);
		}
		free(elem);
		if (andor == (void *)ERR_SYNTAX)
			return (ERR_SYNTAX);
	}
	return (0);
}

t_ptree			*list(t_parser *p)
{
	int		ret;
	t_ptree	*node;
	t_list	*save;

	ret = 0;
	if (!(node = ptree_new(NT_LIST)))
		return (NULL);
	if ((ret = add_to_list(p, node)) == 1)
	{
		save = p->tlst;
		while (parser_expect(p, T_SEMICOL))
		{
			if ((ret = add_to_list(p, node)) == ERR_SYNTAX)
			{
				ptree_free(&node);
				return ((void *)ERR_SYNTAX);
			}
			else if (ret == 0)
			{
				p->tlst = save;
				break ;
			}
			save = p->tlst;
		}
	}
	else
		ptree_free(&node);
	return (ret == ERR_SYNTAX ? (void *)ERR_SYNTAX : node);
}
