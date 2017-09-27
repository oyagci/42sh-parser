/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:58:03 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 14:53:28 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void				free_compound_command(t_compound_command **cpndcmd)
{
	free(*cpndcmd);
	*cpndcmd = NULL;
}

t_compound_command	*compound_command(t_parser *p)
{
	t_compound_command	*cpndcmd;
	t_subshell			*sub;

	if ((cpndcmd = ft_memalloc(sizeof(t_compound_command))))
	{
		if ((sub = subshell(p)))
		{
			if (sub != (void *)ERR_SYNTAX)
				cpndcmd->subshell = sub;
			else
			{
				free_compound_command(&cpndcmd);
				return ((void *)ERR_SYNTAX);
			}
		}
		else
		{
			free_compound_command(&cpndcmd);
			return (NULL);
		}
	}
	return (cpndcmd);
}
