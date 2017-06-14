/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:52:12 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 17:26:27 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <tests.h>

t_parser	*prepare_parser(t_token *tarr, size_t sz, t_ptree *(*f)(t_parser *))
{ 
	t_parser	*p;

	p = ft_memalloc(sizeof(t_parser));
	p->tlst = get_tlst(tarr, sz);
	p->ptree = f(p);
	return (p);
}
