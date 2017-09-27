/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:53:06 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 16:34:31 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <stdlib.h>

void			free_pipe_sequence(t_pipe_sequence **pseq)
{
	t_list	*cmds;
	t_list	*next;

	cmds = (*pseq)->commands;
	while (cmds)
	{
		next = (*pseq)->commands->next;
		free_command((t_command**)&cmds->content);
		free(cmds);
		cmds = next;
	}
	free(*pseq);
	pseq = NULL;
}

int				add_command(t_parser *p, t_pipe_sequence *pseq)
{
	t_list		*elem;
	t_command	*cmd;

	if ((cmd = command(p)))
	{
		if (cmd == (void *)ERR_SYNTAX)
			return (ERR_SYNTAX);
		if ((elem = ft_lstnew(NULL, 0)))
		{
			elem->content = cmd;
			ft_lstpush(&pseq->commands, elem);
			return (1);
		}
		else
			free_command(&cmd);
	}
	return (0);
}

t_pipe_sequence	*pipe_sequence(t_parser *p)
{
	t_pipe_sequence	*pseq;
	unsigned int	ret;

	ret = 0;
	if ((pseq = ft_memalloc(sizeof(t_pipe_sequence))))
	{
		if ((ret = add_command(p, pseq)) == 1)
		{
			while (parser_expect(p, T_PIPE))
			{
				linebreak(p);
				if ((ret = add_command(p, pseq)) != 1)
				{
					free_pipe_sequence(&pseq);
					return ((void *)ERR_SYNTAX);
				}
			}
		}
		else
			free_pipe_sequence(&pseq);
	}
	return (pseq);
}
