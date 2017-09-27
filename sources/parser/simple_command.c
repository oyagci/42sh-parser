/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:51:26 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 13:15:15 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void			free_simple_command(t_simple_command **scmd)
{
	free(*scmd);
}

int				simple_prefix(t_parser *p, t_simple_command *scmd)
{
	if ((scmd->prefix = cmd_prefix(p)))
	{
		if (scmd->prefix == (void *)ERR_SYNTAX)
			return (ERR_SYNTAX);
		if ((scmd->word = cmd_word(p)) == (void *)ERR_SYNTAX)
		{
			free_prefix(&scmd->prefix);
			return (ERR_SYNTAX);
		}
	}
	else if ((scmd->name = cmd_name(p)))
	{
		if (scmd->name == (void *)ERR_SYNTAX)
			return (ERR_SYNTAX);
	}
	else
	{
		free_simple_command(&scmd);
		return (0);
	}
	return (1);
}

t_simple_command		*simple_command(t_parser *p)
{
	int					ret;
	t_simple_command	*scmd;

	if ((scmd = ft_memalloc(sizeof(t_simple_command))))
	{
		if ((ret = simple_prefix(p, scmd)) == 1)
		{
			if ((scmd->suffix = cmd_suffix(p)) == (void *)ERR_SYNTAX)
			{
				free_simple_command(&scmd);
				return ((void *)ERR_SYNTAX);
			}
		}
		else if (ret == 0)
			return (NULL);
		else if (ret == ERR_SYNTAX)
			return ((void *)ERR_SYNTAX);
	}
	return (scmd);
}
