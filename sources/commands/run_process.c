/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:18:40 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/07 13:59:56 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>
#include <unistd.h>
#include <stdlib.h>

int				run_process(t_process *p)
{
	int		ret;
	pid_t	pid;

	ret = 0;
	if (!run_builtin(p->argv))
	{
		if ((pid = fork()) == 0)
		{
			ret = execve_pipeline(p);
			ft_putendl_fd("command not found", 2);
			exit(127);
		}
		else
		{
			waitpid(pid, &ret, WUNTRACED);
			check_if_signal(ret);
		}
	}
	return (ret);
}
