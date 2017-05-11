/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:20:47 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/11 16:59:52 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>
#include <getline/getline.h>
#include <lexer/lexer.h>
#include <shell/shell.h>
#include <shell/parse.h>
#include <termcap.h>
#include <signal.h>
#include <libft.h>

int				process_line(char *input)
{
	(void)input;
	return (0);
}

void			shell(void)
{
	int		run;
	char	*line;

	run = 1;
	line = NULL;
	while (run)
	{
		signal(SIGINT, sigint_reset_line);
		if (ft_getline(&line) == -1)
			return ;
		process_line(line);
		if (ft_strequ("exit", line))
			run = 0;
		ft_strdel(&line);
	}
}

int				main(void)
{
	environ_load();
	tgetent(NULL, environ_getvalue("TERM"));
	shell();
	return (0);
}
