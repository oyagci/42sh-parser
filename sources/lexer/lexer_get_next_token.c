/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_next_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:43:59 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 11:03:56 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

int				lexer_get_next_token(t_lexer *lex)
{
	if (*lex->input_p == '\0')
	{
		if (lexer_symbol_top(lex) != S_END)
			;
		lexer_delimite_current_token(lex);
		return (1);
	}
	else if (lexer_check_top(lex))
		;
	else if (lexer_check_quote(lex))
		;
	else if (lexer_check_delimite(lex))
		;
	else if (*lex->input_p == '\n')
	{
		lexer_delimite_current_token(lex);
		lexer_current_add_char(lex);
		lexer_delimite_current_token(lex);
	}
	else
		lexer_current_add_char(lex);
	return (OK);
}
