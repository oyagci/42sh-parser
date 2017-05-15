/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:51:34 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 16:14:17 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*io_redirect_new(void)
{
	t_ptree	*node;

	node = NULL;
	if ((node = ft_memalloc(sizeof(t_ptree))))
	{
		node->type = NT_IO_REDIRECT;
		if (!(node->content.io_redirect = ft_memalloc(sizeof(t_io_redirect))))
			del_node(node);
	}
	return (node);
}

t_ptree			*io_redirect(t_parser *p)
{
	t_list	*head;
	t_ptree	*node;
	int		ionumber;

	head = p->tlst;
	if ((node = io_redirect_new()))
	{
		if ((ionumber = (((t_token *)head->content)->type == T_IO_NUMBER)))
		{
			node->content.io_redirect->io_number = ionumber;
			p->tlst = p->tlst->next;
			if ((node->content.io_redirect->io_file = io_file(p)))
				return (node);
			else if (node->content.io_redirect->io_here == io_here(p))
				return (node);
		}
		else if ((node->content.io_redirect->io_file = io_file(p)))
		{
			node->content.io_redirect->io_number = 1;
			return (node);
		}
		else if ((node->content.io_redirect->io_here = io_here(p)))
		{
			node->content.io_redirect->io_number = 0;
			return (node);
		}
	}
	return (node);
}
