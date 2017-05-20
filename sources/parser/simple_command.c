/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:51:26 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 16:36:50 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*simple_command(t_parser *p)
{
	t_ptree	*node;

	if ((node = ptree_new(NT_SIMPLE_COMMAND)))
	{
		if (!(node->content->sp_command.prefix = cmd_prefix(p)))
			node->content->sp_command.name = cmd_name(p);
		else if (!(node->content->sp_command.word = cmd_word(p)))
			ptree_free(&node);
		node->content->sp_command.suffix = cmd_suffix(p);
	}
	return (node);
}
