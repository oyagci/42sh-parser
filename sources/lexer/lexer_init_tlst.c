/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init_tlst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:18:24 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 10:49:01 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <stdlib.h>

int				lexer_init_tlst(t_lexer *lexer)
{
	t_list	*elem;

	if ((elem = ft_lstnew(NULL, 0)) == NULL)
		return (ERR);
	if ((elem->content = ft_memalloc(sizeof(t_token))) == NULL)
	{
		free(elem);
		return (ERR);
	}
	((t_token *)elem->content)->type = T_END;
	ft_lstadd(&lexer->tlst, elem);
	return (OK);
}
