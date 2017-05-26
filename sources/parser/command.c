/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:34:32 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 12:28:03 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

int				cmd_add_redir(t_parser *p, t_ptree *node)
{
	t_ptree	*redir;

	redir = redirect_list(p);
	if (redir != (void *)ERR_SYNTAX)
		node->content->command.redirect = redir;
	else
	{
		ptree_free(&node);
		return (ERR_SYNTAX);
	}
	return (1);
}

t_ptree			*command(t_parser *p)
{
	t_ptree		*node;
	t_ptree		*cmd;

	if ((node = ptree_new(NT_COMMAND)))
	{
		if (!(cmd = simple_command(p)))
			cmd = compound_command(p);
		if (cmd == (void *)ERR_SYNTAX)
		{
			ptree_free(&node);
			return ((void *)ERR_SYNTAX);
		}
		else if (cmd == NULL)
		{
			ptree_free(&node);
			return (NULL);
		}
		if (cmd && cmd->type == NT_COMPOUND_COMMAND)
			if (cmd_add_redir(p, node) != 1)
				return ((void *)ERR_SYNTAX);
		node->content->command.cmd = cmd;
	}
	return (node);
}
