/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_exec_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:09:55 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 10:56:08 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>

t_process	*cmds_exec_command(t_ptree *cmd)
{
	(void)cmd;
//	if (cmd->content->command.cmd->type == NT_SIMPLE_COMMAND)
//		return (cmds_simple_command_get_process(cmd->content->command.cmd));
	return (0);
}
