/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:29:06 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 14:29:19 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void			complete_command_del(t_complete_command *cpcmd)
{
	del_node(cpcmd->list);
	free(cpcmd);
}

t_ptree			*complete_command(t_parser *p)
{
	t_ptree	*node;

	node = NULL;
	if ((node = ptree_new(NT_COMPLETE_COMMAND)))
	{
		if ((node->content->cpcmd.list = list(p)) == NULL)
		{
			del_node(node);
			return (NULL);
		}
		if (((t_token *)p->tlst->content)->type == T_SEMICOL)
			p->tlst = p->tlst->next;
	}
	return (node);
}
