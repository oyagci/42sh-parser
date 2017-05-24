/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:20:47 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 17:34:24 by oyagci           ###   ########.fr       */
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

int				process_line(char *input)
{
	t_lexer		*lex;
	t_parser	*p;

	if ((lex = lexer(input)) == (void *)ERR)
		return (ERR);
	p = ft_memalloc(sizeof(t_parser));
	p->tlst = lex->tlst;
	if ((p->ptree = command(p)))
		print_command(p->ptree, 0);
	lexer_delete(&lex);
	ptree_free(&p->ptree);
	free(p);
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
