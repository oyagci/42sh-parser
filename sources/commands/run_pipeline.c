/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:05:40 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/07 10:30:09 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int				fork_pipeline(t_process *p)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == 0)
	{
		execve_pipeline(p);
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

int				run_pipeline(t_process *p)
{
	if (p->next)
		return (fork_pipeline(p));
	else
		return (run_process(p));
}
