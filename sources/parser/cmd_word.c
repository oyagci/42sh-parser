/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:17:15 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 12:01:35 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void		free_word(t_cmd_word **word)
{
	if (*word != (void*)ERR_SYNTAX && *word && (*word)->data)
		free((*word)->data);
	free(*word);
	*word = NULL;
}

t_cmd_word	*cmd_word(t_parser *p)
{
	t_cmd_word	*word;

	if ((word = ft_memalloc(sizeof(t_cmd_word))))
	{
		if (((t_token *)p->tlst->content)->type == T_WORD)
		{
			if ((word->data =
						ft_strdup(((t_token *)p->tlst->content)->data)))
				p->tlst = p->tlst->next;
			else
				free_word(&word);
		}
		else
			free_word(&word);
	}
	return (word);
}
