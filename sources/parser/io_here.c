/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_here.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:53:18 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 12:50:09 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*io_here(t_parser *p)
{
	t_list	*head;
	t_ptree	*node;

	if ((node = ptree_new(NT_IO_HERE)))
	{
		head = p->tlst;
		if (parser_expect(p, T_DLESS))
		{
			if (!(node->content->io_here.here_end = here_end(p)))
			{
				ptree_free(&node);
				p->tlst = head;
				return ((void *)ERR_SYNTAX);
			}
		}
		else
		{
			ptree_free(&node);
			p->tlst = head;
		}
	}
	return (node);
}
