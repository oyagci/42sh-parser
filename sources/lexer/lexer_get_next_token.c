/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_next_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:43:59 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 11:25:38 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

int				lexer_get_next_token(t_lexer *lex)
{
	if (*lex->input_p == '\0')
	{
		lexer_delimite_current_token(lex);
	}
	return (1);
}
