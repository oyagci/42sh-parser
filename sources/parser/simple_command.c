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

int				add_word(t_parser *p, t_ptree *current)
{
	t_ptree	*node;
	t_list	*elem;

	if ((node = cmd_word(p)))
	{
		if ((elem = ft_lstnew(NULL, 0)))
		{
			elem->content = node;
			ft_lstpush(&current->content->sp_command.words, elem);
			return (1);
		}
		else
			ptree_free(&node);
	}
	return (0);
}

t_ptree			*simple_command(t_parser *p)
{
	t_ptree	*node;

	if ((node = ptree_new(NT_SIMPLE_COMMAND)))
	{
		if (!(node->content->sp_command.prefix = cmd_prefix(p)))
		{
			node->content->sp_command.name = cmd_name(p);
			node->content->sp_command.suffix = cmd_suffix(p);
		}
		else
			while (add_word(p, node))
				;
	}
	return (node);
}
