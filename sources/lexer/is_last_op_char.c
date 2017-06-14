/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_last_op_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:53:00 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 10:53:21 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

int				is_last_opchar(t_lexer *lex)
{
	char	token_c;
	char	input_c;

	token_c = lex->current->data[0];
	input_c = *lex->input_p;
	if (token_c == '<' && (input_c == '<' || input_c == '&'))
		return (1);
	if (token_c == '>' && (input_c == '>' || input_c == '&'))
		return (1);
	if (token_c == '|' && input_c == '|')
		return (1);
	if (token_c == '&' && input_c == '&')
		return (1);
	return (0);
}
