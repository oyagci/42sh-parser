/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_symbol_pop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:40:30 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 13:42:16 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <stdlib.h>

enum e_symbol	lexer_symbol_pop(t_lexer *lex)
{
	t_list			*elem;
	enum e_symbol	sym;

	elem = lex->slst;
	sym = *(enum e_symbol *)elem->content;
	lex->slst = lex->slst->next;
	free(elem->content);
	free(elem);
	return (sym);
}
