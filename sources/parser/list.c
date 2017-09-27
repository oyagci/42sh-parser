/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:43:29 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 15:56:52 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void			free_list(t_nlist **lst)
{
	t_list	*next;

	while ((*lst)->andlst)
	{
		next = (*lst)->andlst->next;
		free_and_or((t_and_or**)&(*lst)->andlst->content);
		free((*lst)->andlst);
		(*lst)->andlst = next;
	}
	free(*lst);
	*lst = NULL;
}

int				add_to_list(t_parser *p, t_nlist *lst)
{
	t_list		*elem;
	t_and_or	*andor;

	if ((elem = ft_lstnew(NULL, 0)))
	{
		if ((andor = and_or(p)) && andor != (void *)ERR_SYNTAX)
		{
			elem->content = andor;
			ft_lstpush(&lst->andlst, elem);
			return (1);
		}
		free(elem);
		if (andor == (void *)ERR_SYNTAX)
			return (ERR_SYNTAX);
	}
	return (0);
}

t_nlist		*list(t_parser *p)
{
	int		ret;
	t_nlist	*lst;
	t_list	*save;

	ret = 0;
	if (!(lst = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if ((ret = add_to_list(p, lst)) == 1)
	{
		save = p->tlst;
		while (parser_expect(p, T_SEMICOL))
		{
			if ((ret = add_to_list(p, lst)) == ERR_SYNTAX)
			{
				free_list(&lst);
				return ((void *)ERR_SYNTAX);
			}
			else if (ret == 0)
			{
				p->tlst = save;
				break ;
			}
			save = p->tlst;
		}
	}
	else
		free_list(&lst);
	return (ret == ERR_SYNTAX ? (void *)ERR_SYNTAX : lst);
}
