/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:52:04 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 17:20:18 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>

int				add_and(t_ptree *node, t_ptree *and)
{
	t_list	*elem;

	if ((elem = ft_lstnew(NULL, 0)))
	{
		elem->content = and;
		ft_lstpush(&node->content->term.andlst, elem);
		return (1);
	}
	return (0);
}

int				add_next_and_or(t_parser *p, t_ptree *node)
{
	t_list	*head;
	t_ptree	*andor;

	head = p->tlst;
	if (!parser_expect(p, T_SEMICOL))
		return (0);
	if ((andor = and_or(p)) == (void *)ERR_SYNTAX)
	{
		p->tlst = head;
		return (ERR_SYNTAX);
	}
	if (!add_and(node, andor))
	{
		ptree_free(&andor);
		return (0);
	}
	return (1);
}

t_ptree			*term(t_parser *p)
{
	t_ptree	*node;
	t_ptree	*and;
	int		ret;

	if ((node = ptree_new(NT_TERM)))
	{
		if ((and = and_or(p)) == (void *)ERR_SYNTAX)
		{
			ptree_free(&node);
			return ((void *)ERR_SYNTAX);
		}
		if (!add_and(node, and))
			ptree_free(&node);
		while ((ret = add_next_and_or(p, node)) == 1)
			;
		if (ret == ERR_SYNTAX)
		{
			ptree_free(&node);
			return ((void *)ERR_SYNTAX);
		}
	}
	return (node);
}
