/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:05:07 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 14:30:19 by oyagci           ###   ########.fr       */
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
	return (IT_NONE);
}

t_ptree				*io_file(t_parser *p)
{
	t_ptree		*node;
	t_ptree		*fname;
	enum e_io_type	type;

	if ((node = ptree_new(NT_IO_FILE)))
	{
		if ((type = is_redir_token(((t_token *)p->tlst->content)->type)) !=
				IT_NONE)
		{
			p->tlst = p->tlst->next;
			if ((fname = filename(p)))
				node->content->io_file.filename = fname;
			else
			{
				del_node(node);
				return (NULL);
			}
			p->tlst = p->tlst->next;
		}
		else
		{
			del_node(node);
			return (NULL);
		}
	}
	return (node);
}
