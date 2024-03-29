/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:34:32 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 13:24:18 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void			free_command(t_command **cmd)
{
	if (!*cmd || *cmd == (void*)ERR_SYNTAX)
		return ;
	free_simple_command(&(*cmd)->scmd);
	free_compound_command(&(*cmd)->cpndcmd);
	free(*cmd);
	*cmd = NULL;
}

int				cmd_add_redir(t_parser *p, t_command *cmd)
{
	t_redirect_list	*redir;

	redir = redirect_list(p);
	if (redir != (void *)ERR_SYNTAX)
		cmd->rlist = redir;
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
	t_compound_command	*cpcmd;

	scmd = NULL;
	cpcmd = NULL;
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
		cmd->type = CT_SIMPLE_COMMAND;
		if (cpcmd)
		{
			cmd->type = CT_COMPOUND_COMMAND;
			cmd->cpndcmd = cpcmd;
			if (cmd_add_redir(p, cmd) != 1)
				return ((void *)ERR_SYNTAX);
		}
		cmd->scmd = scmd;
	}
	return (cmd);
}
