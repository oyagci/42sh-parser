/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:53:05 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/07 17:20:21 by oyagci           ###   ########.fr       */
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

void		dup_fd(int in, int out, int to_close)
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
}

pid_t		execve_fd(int in, int out, t_process *p, int to_close)
{
	pid_t	pid;

	if ((pid = fork()) == 0)
	{
		dup_fd(in, out, to_close);
		execve(p->argv[0], p->argv, environ_get_str());
		exit(127);
	}
	else
		return (pid);
}

int			cmds_pipeline_builtin(int in, int out, t_process *p, int to_close)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	ret = 0;
	if (pid > 0)
	{
		waitpid(pid, &ret, WUNTRACED);
		check_if_signal(ret);
		return (ret);
	}
	else if (pid == 0)
	{
		if (is_builtin(p->argv[0]))
		{
			dup_fd(in, out, to_close);
			if ((ret = run_builtin(p->argv)))
				exit(ret);
		}
		exit(127);
	}
	return (-1);
}

int			launch_command(int in, int out, t_process *p, int to_close)
{
	int	ret;

	ret = 0;
	if ((ret = cmds_pipeline_builtin(in, out, p, to_close)) == 127)
	{
		find_path(p->argv);
		ret = execve_fd(in, out, p, to_close);
	}
	return (ret);
}

int			execve_pipeline(t_process *p)
{
	int		fd[2];
	int		in;

	in = 0;
	while (p->next)
	{
		pipe(fd);
		if (launch_command(in, fd[1], p, fd[0]) == 127)
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
	return (launch_command(in, 1, p, 0));
}
