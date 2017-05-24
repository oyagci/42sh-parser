/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:34:32 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 16:38:39 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*command(t_parser *p)
{
	t_ptree		*redir;
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
		if (cmd->type == NT_COMPOUND_COMMAND)
		{
			redir = redirect_list(p);
			if (redir != (void *)ERR_SYNTAX)
				node->content->command.redirect = redir;
			else
			{
				ptree_free(&node);
				return ((void *)ERR_SYNTAX);
			}
		}
	}
	return (node);
}
