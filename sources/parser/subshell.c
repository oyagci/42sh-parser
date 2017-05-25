/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:06:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 16:47:27 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*subshell(t_parser *p)
{
	t_ptree	*node;
	t_list	*head;

	ft_putendl("subshell");
	head = p->tlst;
	if (!parser_expect(p, T_LBRACKET))
		return (NULL);
	if ((node = ptree_new(NT_SUBSHELL)))
	{
		if ((node->content->subshell.compound_list = compound_list(p)) ==
				(void *)ERR_SYNTAX || !(parser_expect(p, T_RBRACKET)))
		{
			p->tlst = head;
			ptree_free(&node);
			return ((void *)ERR_SYNTAX);
		}
	}
	ft_putendl("subshell end");
	return (node);
}
