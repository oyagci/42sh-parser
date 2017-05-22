/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:43:31 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 16:05:03 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*cmd_name(t_parser *p)
{
	t_list	*head;
	t_ptree	*node;

	head = p->tlst;
	if ((node = ptree_new(NT_CMD_NAME)))
	{
		if (((t_token *)p->tlst->content)->type == T_WORD)
		{
			if ((node->content->cmd_name.data =
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
