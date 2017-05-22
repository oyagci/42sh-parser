/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:51:34 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 13:16:15 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

int				get_io_number(t_parser *p, t_ptree *node)
{
	if (((t_token *)p->tlst->content)->type == T_IO_NUMBER)
	{
		node->content->io_redirect.io_number =
			ft_atoi(((t_token *)p->tlst->content)->data);
		node->content->io_redirect.is_default = 0;
		p->tlst = p->tlst->next;
	}
	else
		node->content->io_redirect.is_default = 1;
	return (0);
}

#include <stdio.h>
t_ptree			*io_redirect(t_parser *p)
{
	t_ptree	*io;
	t_ptree	*node;
	t_list	*head;
	int		ionumber;

	ionumber = 0;
	io = NULL;
	if ((node = ptree_new(NT_IO_REDIRECT)))
	{
		head = p->tlst;
		get_io_number(p, node);
		!(io = io_file(p)) ? (io = io_here(p)) : 0;
		if (io && io != (void *)ERR_SYNTAX)
		{
			if (io->type == NT_IO_HERE)
				node->content->io_redirect.io_here = io;
			else if (io->type == NT_IO_FILE)
				node->content->io_redirect.io_file = io;
		}
		else
			ptree_free(&node);
	}
	return ((io == (void *)ERR_SYNTAX) ? (void *)ERR_SYNTAX : node);
}
