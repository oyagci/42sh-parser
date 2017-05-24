/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:39:16 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 12:42:40 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*newline_list(t_parser *p)
{
	if (p->tlst)
	{
		while (((t_token *)p->tlst->content)->type == T_NEWLINE)
		{
			p->tlst = p->tlst->next;
		}
	}
	return (NULL);
}
