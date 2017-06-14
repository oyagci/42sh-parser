/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:29:06 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/14 14:27:18 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

t_ptree			*complete_command(t_parser *p)
{
	t_ptree	*node;

	node = NULL;
	if ((node = ptree_new(NT_COMPLETE_COMMAND)))
	{
		if ((node->content->cpcmd.list = list(p)) == NULL)
		{
			ptree_free(&node);
			return (NULL);
		}
		else if (node->content->cpcmd.list == (void *)ERR_SYNTAX)
		{
			ptree_free(&node);
			return ((void *)ERR_SYNTAX);
		}
		node->content->cpcmd.separator_op = separator_op(p);
	}
	return (node);
}
