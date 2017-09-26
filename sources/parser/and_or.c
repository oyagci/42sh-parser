/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:50:56 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/26 16:43:10 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void			free_and_or(t_and_or **andor)
{
	// TODO: free t_list *pipelines
	free(*andor);
	*andor = NULL;
}

int				add_pipeline(t_pipeline *pline, t_and_or *andor)
{
	t_list	*elem;

	if (pline)
	{
		if ((elem = ft_lstnew(NULL, 0)))
		{
			elem->content = pline;
			ft_lstpush(&andor->pipelines, elem);
			return (1);
		}
	}
	return (0);
}

enum e_pipeline	get_and_or_type(t_parser *p)
{
	if (parser_expect(p, T_AND_IF))
		return (PL_AND_IF);
	else if (parser_expect(p, T_OR_IF))
		return (PL_OR_IF);
	return (PL_DEFAULT);
}

int				add_next_pipeline(t_parser *p, t_and_or *andor)
{
	enum e_pipeline	type;
	t_pipeline		*pline;
	t_list			*head;

	head = p->tlst;
	if ((type = get_and_or_type(p)) == PL_DEFAULT)
		return (0);
	if ((pline = pipeline(p)) == (void *)ERR_SYNTAX || !pline)
	{
		p->tlst = head;
		return (ERR_SYNTAX);
	}
	pline->type = type;
	if (!add_pipeline(pline, andor))
	{
		free_and_or(&andor);
		return (0);
	}
	return (1);
}

t_and_or		*and_or(t_parser *p)
{
	t_and_or		*andor;
	t_pipeline		*pline;
	int				ret;

	if (!(andor = ft_memalloc(sizeof(t_and_or))))
		return (NULL);
	if ((pline = pipeline(p)) == (void *)ERR_SYNTAX)
	{
		free_and_or(&andor);
		return ((void *)ERR_SYNTAX);
	}
	if (!add_pipeline(pline, andor))
		free_and_or(&andor);
	else
	{
		pline->type = PL_DEFAULT;
		while ((ret = add_next_pipeline(p, andor)) == 1)
			;
		if (ret == ERR_SYNTAX)
		{
			free_and_or(&andor);
			return ((void *)ERR_SYNTAX);
		}
	}
	return (andor);
}
