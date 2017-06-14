/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linebreak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:42:50 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 12:57:56 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>

t_ptree			*linebreak(t_parser *p)
{
	newline_list(p);
	return (NULL);
}
