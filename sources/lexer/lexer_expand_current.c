/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand_current.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:06:16 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 11:40:41 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <lexer/expand.h>

int				expand_variable(char *input)
{

}

int				lexer_expand_current(t_lexer *lex)
{
	enum e_quote	type;
	size_t			i;

	type = Q_NONE;
	i = 0;
	while (lex->current->data[i] != 0)
	{
		if (lex->current->data[i] == '\\')
			type = Q_BACKSLASH;
		else if (lex->current->data[i] == '"' && type != Q_BACKSLASH)
			type = (type != Q_DOUBLE ? Q_DOUBLE : Q_NONE);
		else if (lex->current->data[i] == '\'' && type != Q_BACKSLASH)
			type = (type != Q_SINGLE ? Q_SINGLE : Q_NONE);

		if (type == Q_DOUBLE)
		{
			if (lex->current->data[i] == '$')
				expand_variable(&lex->current->data[i + 1]);
		}
		i += 1;
	}
	return (1);
}
