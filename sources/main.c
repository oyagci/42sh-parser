/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:20:47 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 15:42:25 by oyagci           ###   ########.fr       */
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
#include <parser/parser.h>
#include <stdlib.h>
#include <commands/commands.h>
#include <unistd.h>

int				process_line(char *input)
{
	t_lexer		*lex;
	t_parser	*p;

	if ((lex = lexer(input)) == (void *)ERR)
		return (ERR);
	p = ft_memalloc(sizeof(t_parser));
	p->tlst = lex->tlst;
	p->cplcmd = complete_command(p);
	if (p->cplcmd == (void *)ERR_SYNTAX || p->tlst->next)
		ft_putendl("syntax error");
	else
	{
		// print_complete_command(p->cplcmd, 0);
		free_complete_command(&p->cplcmd);
	}
	free(p);
	lexer_delete(&lex);
	return (OK);
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
		if (process_line(line) == ERR)
		{
			ft_putendl("ALERT: An error occured!");
			break ;
		}
		ft_strdel(&line);
	}
}

void			non_interactive(void)
{
	char *line;

	get_next_line(0, &line);
	process_line(line);
	free(line);
}

int				main(void)
{
	environ_load();
	tgetent(NULL, environ_getvalue("TERM"));
	if (isatty(STDIN_FILENO))
		shell();
	else
		non_interactive();
	return (0);
}
