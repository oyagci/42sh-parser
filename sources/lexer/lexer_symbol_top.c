/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_symbol_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:21:21 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 12:31:07 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

enum e_symbol		lexer_symbol_top(t_lexer *lex)
{
	return (*(enum e_symbol *)lex->slst->content);
}
