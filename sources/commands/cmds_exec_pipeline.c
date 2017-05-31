/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_exec_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:42:54 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/31 16:58:50 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>
#include <parser/parser.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int				cmds_exec_pipeline(t_ptree *pline)
{
	t_process 	*process;
	pid_t		pid;
	int			ret;

	ret = 0;
	process = cmds_exec_pipe_sequence(pline->content->pipeline.pipe_sequence);
	pid = fork();
	if (pid == 0)
	{
		execve_pipeline(process);
		ft_putstr_fd("Commmand not found: ", 2);
		ft_putendl_fd(process->argv[0], 2);
		exit(0);
	}
	else
		waitpid(pid, &ret, WUNTRACED);
	return (ret);
}
