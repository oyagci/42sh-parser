/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:17:23 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 13:01:06 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void			free_redirect_list(t_redirect_list **rlist)
{
	free(*rlist);
	*rlist = NULL;
}

int				add_redir(t_redirect_list *rlist, t_io_redirect *redir)
{
	t_list	*elem;

	if ((elem = ft_lstnew(NULL, 0)))
	{
		elem->content = redir;
		ft_lstpush(&rlist->list, elem);
		return (1);
	}
	return (0);
}

t_redirect_list	*redirect_list(t_parser *p)
{
	t_io_redirect	*redir;
	t_redirect_list	*rlist;
	t_list			*head;

	redir = NULL;
	if ((rlist = ft_memalloc(sizeof(t_redirect_list))))
	{
		head = p->tlst;
		if ((redir = io_redirect(p)) && redir != (void *)ERR_SYNTAX)
		{
			add_redir(rlist, redir);
			while ((redir = io_redirect(p)))
				add_redir(rlist, redir);
		}
		else
			free_redirect_list(&rlist);
	}
	return (redir == (void *)ERR_SYNTAX ? (void *)ERR_SYNTAX : rlist);
}
