/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_delimite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:51:31 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 10:51:42 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

int				lexer_check_delimite(t_lexer *lex)
{
	if (lexer_symbol_top(lex) == S_OP)
	{
		if (is_last_opchar(lex))
			lexer_current_add_char(lex);
		lexer_delimite_current_token(lex);
		lexer_symbol_pop(lex);
		return (1);
	}
	else if (is_opstart(lex))
	{
		lexer_delimite_current_token(lex);
		lexer_current_add_char(lex);
		lexer_symbol_push(lex, S_OP);
		return (1);
	}
	else if (ft_isspace(*lex->input_p))
	{
		lexer_delimite_current_token(lex);
		while (ft_isspace(*lex->input_p))
			lex->input_p += 1;
		return (1);
	}
	return (0);
}
