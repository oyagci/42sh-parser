/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:57:01 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/11 17:01:13 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell/builtins/builtin_env.h>
#include <environ/environ.h>
#include <shell/shell.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int				exec_bin(char *av[], char *env[])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(av[0], av, env);
		ft_putstr("No such file or directory: ");
		ft_putendl(av[0]);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
		return (0);
	}
	return (0);
}

int				env_cmd(t_list *assignments, char *av[], int empty_env)
{
	t_list	*env;
	char	**env_str;

	env = get_custom_env(empty_env, assignments);
	env_str = environ_get_str_custom(env);
	/* cmd_find_path(av); */
	exec_bin(av, env_str);
	ft_strsplit_free(env_str);
	ft_lstdel(&env, del_env);
	return (0);
}
