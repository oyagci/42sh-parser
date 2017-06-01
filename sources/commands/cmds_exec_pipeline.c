/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_exec_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:42:54 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/01 13:06:45 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>
#include <parser/parser.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int				cmds_exec_pipeline(t_ptree *pline)
{
	t_process 	*proc;
	pid_t		pid;
	int			ret;

	ret = 0;
	pid = fork();
	if (pid == 0)
	{
		proc = cmds_exec_pipe_sequence(pline->content->pipeline.pipe_sequence);
		execve_pipeline(proc);
		ft_putendl_fd("commmand not found", 2);
		exit(127);
	}
	else
		waitpid(pid, &ret, WUNTRACED);
	return (ret);
}
