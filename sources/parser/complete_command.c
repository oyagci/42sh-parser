/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:29:06 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 12:23:21 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void				free_complete_command(t_complete_command **cplcmd)
{
	if (!*cplcmd || *cplcmd == (void*)ERR_SYNTAX)
		return ;
	free_list(&(*cplcmd)->list);
	free_separator_op(&(*cplcmd)->sepop);
	free(*cplcmd);
	*cplcmd = NULL;
}

t_complete_command	*complete_command(t_parser *p)
{
	t_complete_command *cplcmd;

	if ((cplcmd = ft_memalloc(sizeof(t_complete_command))))
	{
		if (NULL == (cplcmd->list = list(p)))
		{
			free_complete_command(&cplcmd);
			return (NULL);
		}
		else if (cplcmd->list == (void *)ERR_SYNTAX)
		{
			free_complete_command(&cplcmd);
			return ((void *)ERR_SYNTAX);
		}
		cplcmd->sepop = separator_op(p);
	}
	return (cplcmd);
}
