/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_here.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:53:18 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 13:31:23 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void		free_io_here(t_io_here **iohere)
{
	if (!*iohere || *iohere == (void*)ERR_SYNTAX)
		return ;
	free_here_end(&(*iohere)->here_end);
	free(*iohere);
	*iohere = NULL;
}

t_io_here	*io_here(t_parser *p)
{
	t_list		*head;
	t_io_here	*iohere;

	if ((iohere = ft_memalloc(sizeof(t_io_here))))
	{
		head = p->tlst;
		if (parser_expect(p, T_DLESS))
		{
			if (!(iohere->here_end = here_end(p)))
			{
				free_io_here(&iohere);
				p->tlst = head;
				return ((void *)ERR_SYNTAX);
			}
		}
		else
		{
			free_io_here(&iohere);
			p->tlst = head;
		}
	}
	return (iohere);
}
