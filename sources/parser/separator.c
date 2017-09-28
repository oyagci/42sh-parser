/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:47:35 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 13:37:28 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <stdlib.h>

void		free_separator(t_separator **s)
{
	if (!*s || *s == (void*)ERR_SYNTAX)
		return ;
	free_separator_op(&(*s)->sepop);
	free(*s);
	*s = NULL;
}

t_separator	*separator(t_parser *p)
{
	t_separator	*sep;

	if ((sep = ft_memalloc(sizeof(t_separator))))
	{
		if ((sep->sepop = separator_op(p)))
			linebreak(p);
		else
			newline_list(p);
	}
	return (sep);
}
