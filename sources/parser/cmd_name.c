/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:43:31 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 14:28:24 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*cmd_name(t_parser *p)
{
	t_list	*head;
	t_ptree	*node;

	head = p->tlst;
	node = NULL;
	if (((t_token *)head->content)->type == T_WORD)
	{
		if (!(node = ptree_new(NT_CMD_NAME)))
			return (NULL);
		node->content->cmd_name.data =
			ft_strdup(((t_token *)head->content)->data);
		p->tlst = head->next;
	}
	return (node);
}
