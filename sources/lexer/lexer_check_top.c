/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:54:35 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 10:54:47 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

int				lexer_check_top(t_lexer *lex)
{
	if (lexer_symbol_top(lex) == S_QUOTE)
	{
		if (*lex->input_p == '\'')
			lexer_symbol_pop(lex);
		lexer_current_add_char(lex);
		return (1);
	}
	else if (lexer_symbol_top(lex) == S_BSLASH)
	{
		lexer_current_add_char(lex);
		lexer_symbol_pop(lex);
		return (1);
	}
	else if (lexer_symbol_top(lex) == S_DQUOTE)
	{
		if (*lex->input_p == '"')
			lexer_symbol_pop(lex);
		lexer_current_add_char(lex);
		return (1);
	}
	return (0);
}
