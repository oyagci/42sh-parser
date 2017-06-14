/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_symbol_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:08:03 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 13:10:40 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <stdlib.h>

int				lexer_symbol_push(t_lexer *lex, enum e_symbol sym)
{
	t_list	*elem;

	if ((elem = ft_memalloc(sizeof(t_list))) == NULL)
		return (ERR);
	if ((elem->content = ft_memalloc(sizeof(enum e_symbol))) == NULL)
	{
		free(elem);
		return (ERR);
	}
	*(enum e_symbol *)elem->content = sym;
	elem->next = lex->slst;
	lex->slst = elem;
	return (OK);
}
