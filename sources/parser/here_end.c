/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:59:44 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 13:30:09 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <stdlib.h>

void		free_here_end(t_here_end **hend)
{
	if (!*hend || *hend == (void*)ERR_SYNTAX)
		return ;
	free((*hend)->data);
	free(*hend);
	*hend = NULL;
}

t_here_end	*here_end(t_parser *p)
{
	t_here_end	*hend;

	if ((hend = ft_memalloc(sizeof(t_here_end))))
	{
		if (parser_peek(p, T_WORD) && (hend->data =
				ft_strdup(((t_token *)p->tlst->content)->data)))
			p->tlst = p->tlst->next;
		else
			free_here_end(&hend);
	}
	return (hend);
}
