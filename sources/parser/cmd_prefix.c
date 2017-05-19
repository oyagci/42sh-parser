/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:12:51 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 16:21:07 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <stdlib.h>

int				add_assignement(t_parser *p, t_ptree *node)
{
	t_list	*elem;

	if (((t_token *)p->tlst->content)->type == T_ASSIGNEMENT_WORD)
	{
		if ((elem = ft_lstnew(NULL, 0)) && (elem->content =
						ft_strdup(((t_token *)p->tlst->content)->data)))
		{
			p->tlst = p->tlst->next;
			ft_lstpush(&node->content->cmd_prefix.assignements, elem);
			return (1);
		}
		else
			free(elem);
	}
	return (0);
}

t_ptree			*cmd_prefix(t_parser *p)
{
	t_ptree	*node;
	t_list	*head;

	if ((node = ptree_new(NT_CMD_PREFIX)))
	{
		head = p->tlst;
		if (add_assignement(p, node) || add_redirection(p, node))
			while (add_assignement(p, node) || add_redirection(p, node))
				;
		else
		{
			p->tlst = head;
			ptree_free(&node);
		}
	}
	return (node);
}
