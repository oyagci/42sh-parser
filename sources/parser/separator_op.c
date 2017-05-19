/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:59:04 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 13:05:01 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree				*separator_op(t_parser *p)
{
	t_ptree	*node;

	if ((node = ptree_new(NT_SEPARATOR_OP)))
	{
		if (((t_token *)p->tlst->content)->type == T_SEMICOL)
			node->content->separator_op.op = SP_SEMICOL;
		else
			ptree_free(&node);
	}
	return (node);
}
