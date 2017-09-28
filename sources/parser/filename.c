/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:02:58 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 12:13:16 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <environ/environ.h>
#include <stdlib.h>

void			free_filename(t_filename **fname)
{
	if (!*fname || *fname == (void*)ERR_SYNTAX)
		return ;
	free((*fname)->data);
	free(*fname);
	*fname = NULL;
}

int				tilde_expansion(t_token *t)
{
	(void)t;
	return (OK);
}

int				parameter_expansion(t_token *t)
{
	(void)t;
	return (OK);
}

int				quote_removal(t_token *t)
{
	(void)t;
	return (OK);
}

t_filename		*filename(t_parser *p)
{
	t_filename	*fname;
	t_token		*t;

	if ((fname = ft_memalloc(sizeof(t_filename))))
	{
		if ((t = p->tlst->content)->type == T_WORD)
		{
			tilde_expansion(t);
			parameter_expansion(t);
			quote_removal(t);
			if ((fname->data = ft_strdup(t->data)) == NULL)
			{
				free_filename(&fname);
				return (NULL);
			}
			p->tlst = p->tlst->next;
		}
		else
			free_filename(&fname);
	}
	return (fname);
}
