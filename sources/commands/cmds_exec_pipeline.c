/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_exec_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:42:54 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 14:55:43 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>
#include <parser/parser.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

static char		*get_signal_msg(int signal)
{
	static char *const msg[] = {
		0, "hangup", NULL, "quit", "illegal instruction", "trace trap", "abort",
		"emt instrustion", "floating point exception", "killed", "bus error",
		"segmentation fault", "invalid system call", NULL, "alarm",
		"terminated", NULL, "stopped", "stopped", NULL, NULL,
		"suspended (tty input)", "suspended (tty input)", NULL,
		"cpu limit exceeded", "file size limit exceeded", "virtual alarm",
		"profile signal", NULL, NULL, "user defined signal 1",
		"user defined signal 2"
	};

	return (msg[signal]);
}

int				check_if_signal(int ret)
{
	if (WIFSIGNALED(ret))
	{
		ft_putendl_fd(get_signal_msg(WTERMSIG(ret)), 2);
		return (1);
	}
	return (0);
}

int				cmds_exec_pipeline(t_ptree *pline)
{
	t_process	*proc;
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
	{
		waitpid(pid, &ret, WUNTRACED);
		check_if_signal(ret);
	}
	return (ret);
}
