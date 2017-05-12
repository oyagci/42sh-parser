/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_current_add_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:49:49 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 13:18:09 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <stdlib.h>

int				lexer_current_add_char(t_lexer *lex)
{
	char	*tmp;
	if (!lex->current)
	{
		if ((lex->current = ft_memalloc(sizeof(t_token))) == NULL)
			return (ERR);
		lex->current->data = ft_strnew(0);
	}
	tmp = ft_strcjoin(lex->current->data, *lex->input_p);
	free(lex->current->data);
	lex->current->data = tmp;
	lex->input_p += 1;
	return (OK);
}
