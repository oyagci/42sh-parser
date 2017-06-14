/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_exec_single_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:02:26 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/07 15:22:25 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>
#include <sys/wait.h>
#include <unistd.h>
#include <environ/environ.h>
#include <stdlib.h>

int				cmds_exec_builtin(t_process *p)
{
	return (run_builtin(p->argv));
}

int				cmds_exec_bin(t_process *p)
{
	int		ret;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		find_path(p->argv);
		execve(p->argv[0], p->argv, environ_get_str());
		exit(127);
	}
	else
	{
		waitpid(pid, &ret, WUNTRACED);
		check_if_signal(ret);
	}
	return (0);
}

int				cmds_exec_single_command(t_process *p)
{
	int	ret;

	if (!(ret = cmds_exec_builtin(p)))
		ret = cmds_exec_bin(p);
	return (ret);
}
