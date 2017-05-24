/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:51:26 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 17:36:29 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*simple_command(t_parser *p)
{
	t_ptree	*node;

	if ((node = ptree_new(NT_SIMPLE_COMMAND)))
	{
		if ((node->content->sp_command.prefix = cmd_prefix(p)))
		{
			if (node->content->sp_command.prefix == (void *)ERR_SYNTAX)
				return ((void *)ERR_SYNTAX);
			if ((node->content->sp_command.word = cmd_word(p)) ==
					(void *)ERR_SYNTAX)
			{
				ptree_free(&node);
				return ((void *)ERR_SYNTAX);
			}
		}
		else if ((node->content->sp_command.name = cmd_name(p)))
		{
			if (node->content->sp_command.name == (void *)ERR_SYNTAX)
				return ((void *)ERR_SYNTAX);
		}
		else
		{
			ptree_free(&node);
			return (node);
		}
		if ((node->content->sp_command.suffix = cmd_suffix(p)) ==
				(void *)ERR_SYNTAX)
		{
			ptree_free(&node);
			return ((void *)ERR_SYNTAX);
		}
	}
	return (node);
}
