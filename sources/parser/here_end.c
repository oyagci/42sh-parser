/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:59:44 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 15:11:49 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>

t_ptree			*here_end(t_parser *p)
{
	t_ptree	*node;

	if ((node = ptree_new(NT_HERE_END)))
	{
		if (parser_peek(p, T_WORD))
		{
			if (!(node->content->here_end.data =
				ft_strdup(((t_token *)p->tlst->content)->data)))
			{
				/* TODO: Free memory */
				return (NULL);
			}
			p->tlst = p->tlst->next;
		}
		else
		{
			/* TODO: Free memory */
			return (NULL);
		}
	}
	return (node);
}
