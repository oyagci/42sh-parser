/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:41:40 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 10:49:47 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>

t_ptree			*compound_list(t_parser *p)
{
	t_ptree	*node;

	if ((node = ptree_new(NT_COMPOUND_LIST)))
	{
		linebreak(p);
		if ((node->content->compound_list.term = term(p)) == (void *)ERR_SYNTAX)
		{
			ptree_free(&node);
			return ((void *)ERR_SYNTAX);
		}
		parser_expect(p, T_SEMICOL);
	}
	return (node);
}
