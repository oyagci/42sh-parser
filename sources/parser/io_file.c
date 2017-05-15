/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:05:07 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 15:40:14 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

t_ptree				*io_file_new(void)
{
	t_ptree	*node;

	node = NULL;
	if ((node = ft_memalloc(sizeof(t_ptree))))
	{
		node->type = NT_IO_FILE;
		if ((node->content.io_file = ft_memalloc(sizeof(t_io_file))) == NULL)
		{
			free(node);
			return (NULL);
		}
		node->content.io_file->type = IT_GREAT;
		node->content.io_file->filename = NULL;
	}
	return (node);
}

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
	t_ptree			*node;
	t_list			*head;
	enum e_io_type	type;

	head = p->tlst;
	node = NULL;
	if ((node = io_file_new()) &&
			(type = is_redir_token(((t_token *)head->content)->type)) != IT_NONE)
	{
		p->tlst = p->tlst->next;
		if (!(node->content.io_file->filename = filename(p)))
			del_node(node);
	}
	return (node);
}
