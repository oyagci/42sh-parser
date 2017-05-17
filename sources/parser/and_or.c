/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:50:56 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/17 13:19:25 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree				*and_or_new(void)
{
	t_ptree	*node;

	node = NULL;
	if ((node = ft_memalloc(sizeof(t_ptree))))
	{
		node->type = NT_AND_OR;
		if ((node->content.and_or = ft_memalloc(sizeof(t_and_or))) == NULL)
		{
			del_node(node);
			return (NULL);
		}
	}
	return (node);
}

t_ptree				*and_or(t_parser *p)
{
	t_ptree	*node;

	node = NULL;
	if ((node = and_or_new()))
	{
		if (node->content.pipeline = pipeline(p))
			;
	}
	return (node);
}
