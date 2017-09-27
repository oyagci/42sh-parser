/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:12:51 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 13:31:40 by oyagci           ###   ########.fr       */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <stdlib.h>

void			free_prefix(t_cmd_prefix **prefix)
{
	free(*prefix);
	*prefix = NULL;
}

int				add_assignement(t_parser *p, t_cmd_prefix *prefix)
{
	t_list	*elem;

	if (((t_token *)p->tlst->content)->type == T_ASSIGNEMENT_WORD)
	{
		if ((elem = ft_lstnew(NULL, 0)))
		{
			if ((elem->content = ft_strdup(((t_token *)p->tlst->content)->
							data)))
			{
				p->tlst = p->tlst->next;
				ft_lstpush(&prefix->assignements, elem);
				return (1);
			}
		}
		free(elem);
	}
	return (0);
}

int				prefix_add_redirection(t_parser *p, t_cmd_prefix *prefix)
{
	t_list			*elem;
	t_list			*head;
	t_io_redirect	*redir_node;

	head = p->tlst;
	if ((redir_node = io_redirect(p)))
	{
		if (redir_node == (void *)ERR_SYNTAX)
			return (ERR_SYNTAX);
		if ((elem = ft_lstnew(NULL, 0)))
		{
			elem->content = redir_node;
			ft_lstpush(&prefix->redirections, elem);
			return (1);
		}
		free_io_redirect(&redir_node);
		p->tlst = head;
	}
	return (0);
}

int				prefix_add(t_parser *p, t_cmd_prefix *prefix)
{
	int		ret;

	if ((ret = prefix_add_redirection(p, prefix)) == 0)
		return (add_assignement(p, prefix));
	return (ret);
}

t_cmd_prefix	*cmd_prefix(t_parser *p)
{
	t_cmd_prefix	*prefix;
	t_list			*head;
	unsigned int	ret;

	ret = 0;
	if ((prefix = ft_memalloc(sizeof(t_cmd_prefix))))
	{
		head = p->tlst;
		if ((ret = prefix_add(p, prefix)) == 1)
			while ((ret = prefix_add(p, prefix)) == 1)
				;
		else
		{
			p->tlst = head;
			free_prefix(&prefix);
		}
	}
	if (ret == ERR_SYNTAX)
	{
		free_prefix(&prefix);
		return ((void *)ERR_SYNTAX);
	}
	return (prefix);
}
