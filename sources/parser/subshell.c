/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:06:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 13:29:24 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void			free_subshell(t_subshell **subshell)
{
	if (!*subshell || *subshell == (void*)ERR_SYNTAX)
		return ;
	free_compound_list(&(*subshell)->compound_list);
	free(*subshell);
	*subshell = NULL;
}

t_subshell		*subshell(t_parser *p)
{
	t_subshell	*sub;
	t_list		*head;

	head = p->tlst;
	if (!parser_expect(p, T_LBRACKET))
		return (NULL);
	if ((sub = ft_memalloc(sizeof(t_subshell))))
	{
		if ((sub->compound_list = compound_list(p)) ==
				(void *)ERR_SYNTAX || !(parser_expect(p, T_RBRACKET)))
		{
			p->tlst = head;
			free_subshell(&sub);
			return ((void *)ERR_SYNTAX);
		}
	}
	return (sub);
}
