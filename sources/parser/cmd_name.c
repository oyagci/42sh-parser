/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:43:31 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 12:15:17 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void			free_cmd_name(t_cmd_name **cmdname)
{
	if (!*cmdname || *cmdname == (void*)ERR_SYNTAX)
		return ;
	free((*cmdname)->data);
	free(*cmdname);
	*cmdname = NULL;
}

t_cmd_name		*cmd_name(t_parser *p)
{
	t_cmd_name	*cmdname;
	t_list		*head;

	head = p->tlst;
	if ((cmdname = ft_memalloc(sizeof(t_cmd_name))))
	{
		if (((t_token *)p->tlst->content)->type == T_WORD)
		{
			if ((cmdname->data =
						ft_strdup(((t_token *)p->tlst->content)->data)))
				p->tlst = p->tlst->next;
			else
				free_cmd_name(&cmdname);
		}
		else
			free_cmd_name(&cmdname);
	}
	return (cmdname);
}
