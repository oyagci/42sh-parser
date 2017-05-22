/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:29:03 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/17 15:30:10 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

int			parser_expect(t_parser *p, enum e_token type)
{
	if (((t_token *)p->tlst->content)->type != type)
		return (0);
	p->tlst = p->tlst->next;
	return (1);
}
