/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:53:05 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 15:01:59 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <commands/commands.h>
#include <environ/environ.h>

char		**get_paths(void)
{
	char	*envpath;

	if ((envpath = environ_getvalue("PATH")))
		return (ft_strsplit(envpath, ':'));
	else
		return (ft_memalloc(sizeof(char **)));
}

char		*add_pathcomponents(char *a, char *b)
{
	char	*path;
	size_t	len;

	len = ft_strlen(a);
	if (a[len - 1] == '/')
	{
		path = ft_strnew(ft_strlen(a) + ft_strlen(b));
		ft_strcpy(path, a);
	}
	else
	{
		path = ft_strnew(len + ft_strlen(b));
		ft_strcpy(path, a);
		path[len] = '/';
	}
	ft_strcat(path, b);
	return (path);
}

int			find_path(char **name)
{
	char	**paths;
	char	*path;
	size_t	i;

	if (ft_strchr(*name, '/'))
		return (1);
	paths = get_paths();
	i = 0;
	while (paths[i] != 0)
	{
		path = add_pathcomponents(paths[i], *name);
		if (bin_exists(path))
		{
			free(*name);
			*name = path;
			return (1);
		}
		i += 1;
	}
	return (0);
}

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
		if (!find_path(p->argv) || execve_fd(in, fd[1], p, fd[0]) == 127)
			return (127);
		close(fd[1]);
		in = fd[0];
		p = p->next;
	}
	if (in != 0)
	{
		dup2(in, 0);
		close(in);
	}
	if (!find_path(p->argv))
		return (127);
	return (execve(p->argv[0], p->argv, environ_get_str()));
}
