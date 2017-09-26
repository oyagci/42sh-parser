/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:52:04 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/26 15:54:06 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <stdlib.h>

void			free_term(t_term **t)
{
	// TODO: free `t_list *andlst`
	free(*t);
}

int				add_and(t_term *term, t_ptree *and)
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
	t_list	*head;
	t_ptree	*andor;

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
		ptree_free(&andor);
		return (0);
	}
	return (1);
}

t_term			*term(t_parser *p)
{
	t_term	*term;
	t_ptree	*and;
	int		ret;

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
