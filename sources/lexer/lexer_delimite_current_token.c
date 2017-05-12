/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_delimite_current_token.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:58:28 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 12:36:36 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

enum e_token	get_token_type(t_token *t)
{
	char *const			ops[] = { "<<", "<&", ">>", ">&", "||", "&&", "<", ">",
		";", "|" };
	const enum e_token	types[] = { T_DLESS, T_LESSAND, T_DGREAT, T_GREATAND,
		T_OR, T_AND, T_LESS, T_GREAT, T_SEMICOL, T_PIPE };
	size_t const		sz = sizeof(ops) / sizeof(char *);
	size_t				i;

	i = 0;
	while (i < sz)
	{
		if (ft_strequ(t->data, ops[i]))
			return ((enum e_token)types[i]);
		i += 1;
	}
	return (0);
}

int				is_io_number(t_token *t, char *input)
{
	size_t	i;

	if (*input && (*(input + 1) == '>' || *(input + 1) == '<'))
	{
		i = 0;
		while (t->data[i] != 0)
		{
			if (!ft_isdigit(t->data[i]))
				return (0);
			i += 1;
		}
	}
	return (1);
}

int				lexer_delimite_current_token(t_lexer *lex)
{
	enum e_token	type;

	if (lex->current)
	{
		if (is_io_number(lex->current, lex->input_p))
			lex->current->type = T_IO_NUMBER;
		else
		{
			type = get_token_type(lex->current);
			lex->current->type = (type != 0 ? type : T_TOKEN);
		}
	}
	return (OK);
}
