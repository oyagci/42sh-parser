/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_suffix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 13:10:58 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 15:54:45 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <stdlib.h>

int				add_word(t_parser *p, t_ptree *node)
{
	t_list	*elem;

	if (((t_token *)p->tlst->content)->type == T_WORD)
	{
		if ((elem = ft_lstnew(NULL, 0)) && (elem->content =
						ft_strdup(((t_token *)p->tlst->content)->data)))
		{
			p->tlst = p->tlst->next;
			ft_lstpush(&node->content->cmd_suffix.words, elem);
			return (1);
		}
		else
			free(elem);
	}
	return (0);
}

int				add_redirection(t_parser *p, t_ptree *node)
{
	t_list	*elem;
	t_list	*head;
	t_ptree	*redir_node;

	head = p->tlst;
	if ((redir_node = io_redirect(p)))
	{
		if ((elem = ft_lstnew(NULL, 0)))
		{
			elem->content = redir_node;
			ft_lstpush(&node->content->cmd_suffix.redirections, elem);
			return (1);
		}
		else
		{
			ptree_free(&redir_node);
			p->tlst = head;
		}
	}
	else
		ptree_free(&redir_node);
	return (0);
}

t_ptree			*cmd_suffix(t_parser *p)
{
	t_list	*head;
	t_ptree	*node;

	if ((node = ptree_new(NT_CMD_SUFFIX)))
	{
		head = p->tlst;
		if (add_word(p, node) || add_redirection(p, node))
			while (add_word(p, node) || add_redirection(p, node))
				;
		else
		{
			p->tlst = head;
			ptree_free(&node);
		}
	}
	return (node);
}
