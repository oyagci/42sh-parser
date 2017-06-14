/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:59:44 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 17:35:24 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>

t_ptree			*here_end(t_parser *p)
{
	t_ptree	*node;

	if ((node = ptree_new(NT_HERE_END)))
	{
		if (parser_peek(p, T_WORD) && (node->content->here_end.data =
				ft_strdup(((t_token *)p->tlst->content)->data)))
			p->tlst = p->tlst->next;
		else
			ptree_free(&node);
	}
	return (node);
}
