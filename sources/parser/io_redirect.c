/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:51:34 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 12:16:12 by oyagci           ###   ########.fr       */
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
	}
	else
		node->content->io_redirect.is_default = 1;
	return (0);
}

t_ptree			*io_redirect(t_parser *p)
{
	t_ptree	*node;
	t_list	*head;
	int		ionumber;

	ionumber = 0;
	if ((node = ptree_new(NT_IO_REDIRECT)))
	{
		head = p->tlst;
		get_io_number(p, node);
		if (!(node->content->io_redirect.io_file = io_file(p)) &&
				!(node->content->io_redirect.io_here = io_here(p)))
		{
			ptree_free(&node);
			p->tlst = head;
		}
	}
	return (node);
}
