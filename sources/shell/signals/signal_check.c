/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 10:20:16 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/26 13:46:22 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <string.h>
#include <libft.h>
#include <sys/wait.h>

static char		*get_signal_msg(int signal)
{
	static char *const msg[] = {
		0, "Hangup", NULL, "Quit", "Illegal instruction", "Trace trap", "Abort",
		"EMT Instrustion", "Floating point exception", "Killed", "Bus error",
		"Segmentation fault", "Invalid system call", NULL, "Alarm",
		"Terminated", NULL, "Stopped", "Stopped", NULL, NULL,
		"Suspended (tty input)", "Suspended (tty input)", NULL,
		"CPU limit exceeded", "File size limit exceeded", "Virtual alarm",
		"Profile signal", NULL, NULL, "User defined signal 1",
		"User defined signal 2"
	};

	return (msg[signal]);
}

static void		signal_handle(int signal, char *cmd)
{
	char *msg;

	msg = get_signal_msg(signal);
	if (msg)
	{
		ft_putstr_fd("21sh: ", 2);
		ft_putstr_fd(get_signal_msg(signal), 2);
		if (cmd)
		{
			ft_putstr_fd(": ", 2);
			ft_putendl_fd(cmd, 2);
		}
		else
			ft_putchar_fd('\n', 2);
	}
}

void			signal_check(int status, char **av)
{
	int			sig;
	const int	maxsignals = 31;

	sig = 1;
	if (WIFSIGNALED(status))
		while (sig <= maxsignals)
		{
			if (WTERMSIG(status) == sig)
				signal_handle(sig, av ? av[0] : NULL);
			sig += 1;
		}
}
