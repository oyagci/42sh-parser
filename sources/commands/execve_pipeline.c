/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:53:05 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/01 13:06:05 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <commands/commands.h>
#include <environ/environ.h>

char		*base64[] = { "base64", "/dev/urandom", NULL };
char		*head[] = { "head", "-c", "1000", NULL };
char		*grep[] = { "grep", "42", NULL };

pid_t		execve_fd(int in, int out, t_process *p, int to_close)
{
	pid_t	pid;

	if ((pid = fork()) == 0)
	{
		if (out != STDOUT_FILENO)
		{
			dup2(out, STDOUT_FILENO);
			close(out);
		}
		if (in != STDIN_FILENO)
		{
			dup2(in, STDIN_FILENO);
			close(in);
		}
		if (to_close != 0)
			close(to_close);
		execve(p->argv[0], p->argv, environ_get_str());
		exit(127);
	}
	else
		return (pid);
}

int			execve_pipeline(t_process *p)
{
	int		fd[2];
	int		in;

	in = 0;
	while (p->next)
	{
		pipe(fd);
		execve_fd(in, fd[1], p, fd[0]);
		close(fd[1]);
		in = fd[0];
		p = p->next;
	}
	if (in != 0)
	{
		dup2(in, 0);
		close(in);
	}
	return (execve(p->argv[0], p->argv, environ_get_str()));
}
