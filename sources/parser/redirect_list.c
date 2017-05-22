/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:17:23 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 13:21:46 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

int				add_redir(t_ptree *node, t_ptree *redir)
{
	t_list	*elem;

	if ((elem = ft_lstnew(NULL, 0)))
	{
		elem->content = redir;
		ft_lstpush(&node->content->redirect_list.list, elem);
		return (1);
	}
	return (0);
}

t_ptree			*redirect_list(t_parser *p)
{
	t_ptree	*redir;
	t_ptree	*node;
	t_list	*head;

	redir = NULL;
	if ((node = ptree_new(NT_REDIRECT_LIST)))
	{
		head = p->tlst;
		if ((redir = io_redirect(p)) && redir != (void *)ERR_SYNTAX)
		{
			add_redir(node, redir);
			while ((redir = io_redirect(p)))
				add_redir(node, redir);
		}
		else
			ptree_free(&node);
	}
	return (redir == (void *)ERR_SYNTAX ? (void *)ERR_SYNTAX : node);
}
