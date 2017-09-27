/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:34:32 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 10:50:31 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void			free_command(t_command **cmd)
{
	free(*cmd);
	*cmd = NULL;
}

int				cmd_add_redir(t_parser *p, t_command *cmd)
{
	t_ptree	*redir;

	redir = redirect_list(p);
	if (redir != (void *)ERR_SYNTAX)
		cmd->redirect = redir;
	else
	{
		free_command(&cmd);
		return (ERR_SYNTAX);
	}
	return (1);
}

t_command		*command(t_parser *p)
{
	t_command			*cmd;
	t_simple_command	*scmd;
	t_ptree				*cpcmd;

	scmd = NULL;
	if ((cmd = ft_memalloc(sizeof(t_command))))
	{
		if (!(scmd = simple_command(p)))
			cpcmd = compound_command(p);
		if ((scmd == (void*)ERR_SYNTAX || cpcmd == (void*)ERR_SYNTAX))
		{
			free_command(&cmd);
			return ((void *)ERR_SYNTAX);
		}
		else if (scmd == NULL && cpcmd == NULL)
		{
			free_command(&cmd);
			return (NULL);
		}
		if (cpcmd)
		{
			cmd->type = CT_COMPOUND_COMMAND;
			cmd->cpcmd = cpcmd;
			if (cmd_add_redir(p, cmd) != 1)
				return ((void *)ERR_SYNTAX);
		}
		cmd->scmd = scmd;
	}
	return (cmd);
}
