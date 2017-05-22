/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:17:15 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 16:32:03 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*cmd_word(t_parser *p)
{
	t_ptree	*node;

	if ((node = ptree_new(NT_CMD_WORD)))
	{
		if (((t_token *)p->tlst->content)->type == T_WORD)
		{
			if ((node->content->cmd_word.data =
						ft_strdup(((t_token *)p->tlst->content)->data)))
				p->tlst = p->tlst->next;
			else
				ptree_free(&node);
		}
		else
			ptree_free(&node);
	}
	return (node);
}
