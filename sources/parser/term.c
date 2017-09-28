/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:52:04 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 13:27:13 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <stdlib.h>

void			free_term_andlst(t_list *andlst)
{
	t_list	*next;

	while (andlst)
	{
		next = andlst->next;
		free_and_or((t_and_or **)&andlst->content);
		free(andlst);
		andlst = next;
	}
}

void			free_term(t_term **t)
{
	if (!*t || *t == (void*)ERR_SYNTAX)
		return ;
	free_term_andlst((*t)->andlst);
	free(*t);
	*t = NULL;
}

int				add_and(t_term *term, t_and_or *and)
{
	t_list	*elem;

	if ((elem = ft_lstnew(NULL, 0)))
	{
		elem->content = and;
		ft_lstpush(&term->andlst, elem);
		return (1);
	}
	return (0);
}

int				add_next_and_or(t_parser *p, t_term *term)
{
	t_list		*head;
	t_and_or	*andor;

	head = p->tlst;
	if (!parser_expect(p, T_SEMICOL))
		return (0);
	if ((andor = and_or(p)) == (void *)ERR_SYNTAX)
	{
		p->tlst = head;
		return (ERR_SYNTAX);
	}
	if (!add_and(term, andor))
	{
		free_and_or(&andor);
		return (0);
	}
	return (1);
}

t_term			*term(t_parser *p)
{
	t_term		*term;
	t_and_or	*and;
	int			ret;

	if ((term = ft_memalloc(sizeof(t_term))))
	{
		if ((and = and_or(p)) == (void *)ERR_SYNTAX)
		{
			free_term(&term);
			return ((void *)ERR_SYNTAX);
		}
		if (!add_and(term, and))
			free_term(&term);
		while ((ret = add_next_and_or(p, term)) == 1)
			;
		if (ret == ERR_SYNTAX)
		{
			free_term(&term);
			return ((void *)ERR_SYNTAX);
		}
	}
	return (term);
}
