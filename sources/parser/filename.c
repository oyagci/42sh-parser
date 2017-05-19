/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:02:58 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 13:09:56 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <environ/environ.h>
#include <stdlib.h>

int				tilde_expansion(t_token *t)
{
	(void)t;
	/* TODO */
	return (OK);
}

int				parameter_expansion(t_token *t)
{
	(void)t;
	/* TODO */
	return (OK);
}

int				quote_removal(t_token *t)
{
	(void)t;
	/* TODO */
	return (OK);
}

t_ptree			*filename(t_parser *p)
{
	t_ptree	*node;
	t_token	*t;

	if ((node = ptree_new(NT_FILENAME)))
	{
		if ((t = p->tlst->content)->type == T_WORD)
		{
			tilde_expansion(t);
			parameter_expansion(t);
			quote_removal(t);
			if ((node->content->filename.data = ft_strdup(t->data)) == NULL)
			{
				ptree_free(&node);
				return (NULL);
			}
			p->tlst = p->tlst->next;
		}
		else
			ptree_free(&node);
	}
	return (node);
}
