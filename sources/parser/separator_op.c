/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:59:04 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 12:23:16 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void			free_separator_op(t_separator_op **sepop)
{
	free(*sepop);
	*sepop = NULL;
}

t_separator_op	*separator_op(t_parser *p)
{
	t_separator_op *sepop;

	if ((sepop = ft_memalloc(sizeof(t_separator_op))))
	{
		if (((t_token *)p->tlst->content)->type == T_SEMICOL)
		{
			sepop->op = SP_SEMICOL;
			p->tlst = p->tlst->next;
		}
		else if (((t_token *)p->tlst->content)->type == T_AND)
		{
			sepop->op = SP_AND;
			p->tlst = p->tlst->next;
		}
		else
			free_separator_op(&sepop);
	}
	return (sepop);
}
