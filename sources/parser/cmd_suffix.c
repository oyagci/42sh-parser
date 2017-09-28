/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_suffix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 13:10:58 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 12:14:28 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <stdlib.h>

void			free_suffix(t_cmd_suffix **suffix)
{
	t_list	*next;
	t_list	*redirs;

	if (!*suffix || *suffix == (void*)ERR_SYNTAX)
		return ;
	redirs = (*suffix)->redirections;
	while (redirs)
	{
		next = redirs->next;
		free_io_redirect((t_io_redirect **)&redirs->content);
		free(redirs);
		redirs = next;
	}
	free(*suffix);
	*suffix = NULL;
}

int				suffix_add_word(t_parser *p, t_cmd_suffix *suffix)
{
	t_list	*elem;

	if (((t_token *)p->tlst->content)->type == T_WORD)
	{
		if ((elem = ft_lstnew(NULL, 0)))
		{
			if ((elem->content = ft_strdup(((t_token *)p->tlst->content)->
							data)))
			{
				p->tlst = p->tlst->next;
				ft_lstpush(&suffix->words, elem);
				return (1);
			}
		}
		free(elem);
	}
	return (0);
}

int				add_redirection(t_parser *p, t_cmd_suffix *suffix)
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
			ft_lstpush(&suffix->redirections, elem);
			return (1);
		}
		else
		{
			free_io_redirect(&redir_node);
			p->tlst = head;
		}
	}
	return (0);
}

int				suffix_add(t_parser *p, t_cmd_suffix *suffix)
{
	int		ret;

	if ((ret = add_redirection(p, suffix)) == 0)
		return (suffix_add_word(p, suffix));
	return (ret);
}

t_cmd_suffix	*cmd_suffix(t_parser *p)
{
	t_cmd_suffix	*suffix;
	t_list			*head;
	unsigned int	ret;

	ret = 0;
	if ((suffix = ft_memalloc(sizeof(t_cmd_suffix))))
	{
		head = p->tlst;
		if ((ret = suffix_add(p, suffix)) == 1)
			while ((ret = suffix_add(p, suffix)) == 1)
				;
		else
		{
			p->tlst = head;
			free_suffix(&suffix);
		}
	}
	if (ret == ERR_SYNTAX)
	{
		free_suffix(&suffix);
		return ((void *)ERR_SYNTAX);
	}
	return (suffix);
}
