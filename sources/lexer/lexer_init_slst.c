/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init_slst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:25:28 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 12:32:59 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <stdlib.h>

int				lexer_init_slst(t_lexer *lex)
{
	t_list	*elem;

	if ((elem = ft_lstnew(NULL, 0)) == NULL)
		return (ERR);
	if ((elem->content = ft_memalloc(sizeof(enum e_symbol))) == NULL)
	{
		free(elem);
		return (ERR);
	}
	lex->slst = elem;
	*(enum e_symbol *)elem->content = S_END;
	return (OK);
}
