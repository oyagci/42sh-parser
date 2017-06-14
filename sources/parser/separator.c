/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:47:35 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 12:28:56 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>

t_ptree			*separator(t_parser *p)
{
	t_ptree	*node;

	if ((node = ptree_new(NT_SEPARATOR)))
	{
		if ((node->content->separator.separator_op = separator_op(p)))
			linebreak(p);
		else
			newline_list(p);
	}
	return (node);
}
