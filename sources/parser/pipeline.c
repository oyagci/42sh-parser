/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:53:10 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 14:55:39 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>

t_ptree			*pipeline(t_parser *p)
{
	t_ptree	*node;

	node = NULL;
	(void)p;
	if ((node = ptree_new(NT_PIPELINE)))
	{
		node->content->pipeline.pipe_sequence = pipe_sequence(p);
	}
	return (node);
}
