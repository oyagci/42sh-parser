/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:58:03 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 13:25:04 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void				free_compound_command(t_compound_command **cpndcmd)
{
	if (!*cpndcmd || *cpndcmd == (void*)ERR_SYNTAX)
		return ;
	free_subshell(&(*cpndcmd)->subshell);
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
