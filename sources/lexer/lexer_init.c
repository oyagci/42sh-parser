/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:12:39 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 12:19:55 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <stdlib.h>

t_lexer			*lexer_init(char *input)
{
	t_lexer	*lex;

	if ((lex = ft_memalloc(sizeof(t_lexer))) == NULL)
		return ((void *)ERR);
	if (lexer_init_tlst(lex) == ERR)
	{
		free(lex);
		return ((void *)ERR);
	}
	if (lexer_init_slst(lex) == ERR)
	{
		ft_lstdel(&lex->tlst, &lexer_del_token);
		free(lex);
		return ((void *)ERR);
	}
	lex->input_p = input;
	return (lex);
}
