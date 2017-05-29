/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:50:56 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/29 13:49:17 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

int				add_pipeline(t_ptree *pline, t_ptree *node)
{
	t_list	*elem;

	if (pline)
	{
		if ((elem = ft_lstnew(NULL, 0)))
		{
			elem->content = pline;
			ft_lstpush(&node->content->and_or.pipelines, elem);
			return (1);
		}
	}
	return (0);
}

enum e_pipeline	get_and_or_type(t_parser *p)
{
	if (parser_expect(p, T_AND_IF))
		return (PL_AND_IF);
	else if (parser_expect(p, T_OR_IF))
		return (PL_OR_IF);
	return (PL_DEFAULT);
}

int				add_next_pipeline(t_parser *p, t_ptree *node)
{
	enum e_pipeline	type;
	t_ptree			*pline;
	t_list			*head;

	head = p->tlst;
	if ((type = get_and_or_type(p)) == PL_DEFAULT)
		return (0);
	if ((pline = pipeline(p)) == (void *)ERR_SYNTAX)
	{
		p->tlst = head;
		return (ERR_SYNTAX);
	}
	if (!add_pipeline(pline, node))
	{
		ptree_free(&node);
		return (0);
	}
	return (1);
}

t_ptree			*and_or(t_parser *p)
{
	t_ptree			*node;
	t_ptree			*pline;
	int				ret;

	if ((node = ptree_new(NT_AND_OR)))
	{
		if ((pline = pipeline(p)) == (void *)ERR_SYNTAX)
		{
			ptree_free(&node);
			return ((void *)ERR_SYNTAX);
		}
		if (!add_pipeline(pline, node))
			ptree_free(&node);
		else
		{
			pline->content->pipeline.type = PL_DEFAULT;
			while ((ret = add_next_pipeline(p, node)) == 1)
				;
			if (ret == ERR_SYNTAX)
			{
				ptree_free(&node);
				return ((void *)ERR_SYNTAX);
			}
		}
	}
	return (node);
}
