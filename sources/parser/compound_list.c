/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:41:40 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/26 15:50:12 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <stdlib.h>

void				free_compound_list(t_compound_list **cl)
{
	free(cl);
}

t_compound_list		*compound_list(t_parser *p)
{
	t_compound_list	*compound_list;

	if ((compound_list = ft_memalloc(sizeof(t_compound_list))))
	{
		linebreak(p);
		if ((compound_list->term = term(p)) == (void *)ERR_SYNTAX)
		{
			free_compound_list(&compound_list);
			return ((void *)ERR_SYNTAX);
		}
		parser_expect(p, T_SEMICOL);
	}
	return (compound_list);
}
