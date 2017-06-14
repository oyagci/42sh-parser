/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:54:09 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 10:54:28 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

int				lexer_check_quote(t_lexer *lex)
{
	if (*lex->input_p == '\\')
	{
		lexer_symbol_push(lex, S_BSLASH);
		lexer_current_add_char(lex);
		return (1);
	}
	else if (*lex->input_p == '\'')
	{
		lexer_symbol_push(lex, S_QUOTE);
		lexer_current_add_char(lex);
		return (1);
	}
	else if (*lex->input_p == '"')
	{
		lexer_symbol_push(lex, S_DQUOTE);
		lexer_current_add_char(lex);
		return (1);
	}
	return (0);
}
