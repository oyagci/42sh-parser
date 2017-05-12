/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_next_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:43:59 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 13:24:04 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

int				is_opstart(t_lexer *lex)
{
	char const		opstarts[] = { '<', '>', '|', '&', ';' };
	size_t const	sz = sizeof(opstarts) / sizeof(char);
	size_t			i;

	i = 0;
	while (i < sz)
	{
		if (*lex->input_p == opstarts[i])
			return (1);
		i += 1;
	}
	return (0);
}

int				is_last_opchar(t_lexer *lex)
{
	char	token_c;
	char	input_c;

	token_c = lex->current->data[0];
	input_c = *lex->input_p;
	if (token_c == '<' && input_c == '<')
		return (1);
	if (token_c == '<' && input_c == '&')
		return (1);
	return (0);
}

int				lexer_get_next_token(t_lexer *lex)
{
	ft_putendl("lexer_get_next_token");
	if (*lex->input_p == '\0')
	{
		lexer_delimite_current_token(lex);
		return (1);
	}
	else if (lexer_symbol_top(lex) != S_QUOTE)
	{
		if (lexer_symbol_top(lex) != S_OP)
		{
			if (is_opstart(lex))
			{
				lexer_delimite_current_token(lex);
				lexer_current_add_char(lex);
				lexer_symbol_push(lex, S_OP);
			}
		}
		else
		{
			if (is_last_opchar(lex))
			{
				lexer_current_add_char(lex);
				lexer_delimite_current_token(lex);
			}
		}
	}
	/* DEBUGGING */
	lex->current && lex->current->data ? ft_putendl(lex->current->data) : 0;
	return (OK);
}
