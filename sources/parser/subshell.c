/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:06:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 14:19:40 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*subshell(t_parser *p)
{
	t_ptree	*node;
	t_list	*head;

	if (!parser_expect(p, T_LBRACKET))
		return (NULL);
	if ((node = ptree_new(NT_SUBSHELL)))
	{
		head = p->tlst;
		node = compound_list(p);
		if (!(parser_expect(p, T_RBRACKET)))
		{
			ptree_free(&node);
			p->tlst = head;
			return ((void *)ERR_SYNTAX);
		}
	}
	return (node);
}
