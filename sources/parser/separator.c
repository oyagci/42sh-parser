/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:47:35 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 14:54:03 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>

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
