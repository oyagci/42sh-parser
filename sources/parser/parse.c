/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:58:01 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 15:18:23 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>
#include <libft.h>

t_ptree			*parse_internal(t_parser *p)
{
	(void)p;
	return (NULL);
}

t_ptree			*parse(t_list *tlst)
{
	t_parser	p;

	p.tlst = tlst;
	if ((p.ptree = ptree_init()))
		parse_internal(&p);
	return (p.ptree);
}
