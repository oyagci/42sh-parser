/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:58:03 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 14:17:29 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*compound_command(t_parser *p)
{
	t_ptree	*node;
	t_ptree	*sub;

	if ((node = ptree_new(NT_COMPOUND_COMMAND)))
	{
		if ((sub = subshell(p)))
		{
			if (sub != (void *)ERR_SYNTAX)
				node->content->compound_command.subshell = sub;
			else
			{
				ptree_free(&node);
				return ((void *)ERR_SYNTAX);
			}
		}
	}
	return (node);
}
