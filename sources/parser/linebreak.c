/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linebreak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:42:50 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 13:34:27 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>

void		free_linebreak(t_linebreak *lb)
{
	/*
	** Empty struct
	*/
	(void)lb;
}

t_linebreak	*linebreak(t_parser *p)
{
	newline_list(p);
	return (NULL);
}
