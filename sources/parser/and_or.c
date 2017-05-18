/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:50:56 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 13:25:53 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree				*and_or_new(void)
{
	t_ptree	*node;

	node = NULL;
	if ((node = ft_memalloc(sizeof(t_ptree))))
	{
		node->type = NT_AND_OR;
		if ((node->content.and_or = ft_memalloc(sizeof(t_and_or))) == NULL)
		{
			del_node(node);
			return (NULL);
		}
	}
	return (node);
}

enum e_and_or		get_and_or_type(t_parser *p)
{
	if (parser_expect(p, T_AND))
		return (AO_AND);
	else if (parser_expect(p, T_OR))
		return (AO_OR);
	return (AO_UNDEFINED);
}

int					and_or_add_branch(t_parser *p, t_ptree *node, enum e_and_or typw)
{
	t_list	*elem;
	t_ptree	*pline;

	if ((pline = pipeline(p)))
	{
		if ((elem = ft_lstnew(NULL, 0)))
		{
			elem->content = pline;
			ft_lstpush(&node->content.and_or->branches, elem);
			return (1);
		}
		else
			del_node(pline);
	}
	return (0);
}

int					and_or_add_pipeline(t_parser *p, t_ptree *node, int is_first)
{
	enum e_and_or	type;

	type = get_and_or_type(p);
	if (!is_first && type == AO_UNDEFINED)
		return (0);
	p->tlst = p->tlst->next;
	if (and_or_add_branch(p, node, type))
		return (1);
	return (0);
}

t_ptree				*and_or(t_parser *p)
{
	t_ptree	*node;

	node = NULL;
	if ((node = and_or_new()))
	{
		if (and_or_add_pipeline(p, node, 1))
			while (and_or_add_pipeline(p, node, 0))
				;
		else
		{
			del_node(node);
			return (NULL);
		}
	}
	return (node);
}
