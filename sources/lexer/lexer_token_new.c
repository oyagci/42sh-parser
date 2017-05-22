/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:52:09 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 13:55:35 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <stdlib.h>

int				lexer_token_new(t_lexer *lex)
{
	t_token	*t;

	if ((t = ft_memalloc(sizeof(t_token))) == NULL)
		return (ERR);
	if ((t->data = ft_strnew(0)) == NULL)
	{
		free(t);
		return (ERR);
	}
	lex->current = t;
	return (ERR);
}
