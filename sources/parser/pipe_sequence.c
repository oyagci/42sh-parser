/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:53:06 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 10:53:20 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>

int				add_command(t_parser *p, t_ptree *node)
{
	t_list	*elem;
	t_ptree	*cmd;

	if ((cmd = command(p)))
	{
		if (cmd == (void *)ERR_SYNTAX)
			return (ERR_SYNTAX);
		if ((elem = ft_lstnew(NULL, 0)))
		{
			elem->content = cmd;
			ft_lstpush(&node->content->pipe_sequence.commands, elem);
			return (1);
		}
		else
			ptree_free(&cmd);
	}
	return (0);
}

t_ptree			*pipe_sequence(t_parser *p)
{
	t_ptree			*node;
	unsigned int	ret;

	ret = 0;
	if ((node = ptree_new(NT_PIPE_SEQUENCE)))
	{
		if ((ret = add_command(p, node)) == 1)
		{
			while (parser_expect(p, T_PIPE))
			{
				linebreak(p);
				if ((ret = add_command(p, node)) != 1)
					break ;
			}
		}
		else
			ptree_free(&node);
	}
	if (ret == ERR_SYNTAX)
		ptree_free(&node);
	return (ret != ERR_SYNTAX ? node : (void *)ERR_SYNTAX);
}
