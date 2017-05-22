/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:05:07 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 12:39:03 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

enum e_io_type		is_redir_token(enum e_token type)
{
	if (type == T_LESS)
		return (IT_LESS);
	else if (type == T_GREAT)
		return (IT_GREAT);
	else if (type == T_GREATAND)
		return (IT_GREATAND);
	else if (type == T_LESSAND)
		return (IT_LESSAND);
	else if (type == T_DGREAT)
		return (IT_DGREAT);
	return (IT_NONE);
}

t_ptree				*io_file(t_parser *p)
{
	t_ptree			*node;
	t_list			*head;
	enum e_io_type	type;

	if ((node = ptree_new(NT_IO_FILE)))
	{
		if ((type = is_redir_token(((t_token *)p->tlst->content)->type)) !=
				IT_NONE)
		{
			head = p->tlst;
			p->tlst = p->tlst->next;
			node->content->io_file.type = type;
			if (!(node->content->io_file.filename = filename(p)))
			{
				ptree_free(&node);
				p->tlst = head;
				return ((void *)ERR_SYNTAX);
			}
		}
		else
			ptree_free(&node);
	}
	return (node);
}
