/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:29:06 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/17 12:48:20 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

t_ptree			*complete_command_new(void)
{
	t_ptree	*node;

	node = NULL;
	if ((node = ft_memalloc(sizeof(t_ptree))))
	{
		node->type = NT_COMPLETE_COMMAND;
		if (!(node->content.cpcmd = ft_memalloc(sizeof(t_complete_command))))
		{
			del_node(node);
			return (NULL);
		}
	}
	return (node);
}

void			complete_command_del(t_complete_command *cpcmd)
{
	del_node(cpcmd->list);
	free(cpcmd);
}

t_ptree			*complete_command(t_parser *p)
{
	t_ptree	*node;

	node = NULL;
	if ((node = complete_command_new()))
	{
		if ((node->content.cpcmd->list = list(p)) == NULL)
		{
			del_node(node);
			return (NULL);
		}
		if (((t_token *)p->tlst->content)->type == T_SEMICOL)
			p->tlst = p->tlst->next;
	}
	return (node);
}
