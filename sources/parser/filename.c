/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:02:58 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 15:55:59 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*filename_new(void)
{
	t_ptree	*node;

	node = NULL;
	if ((node = ft_memalloc(sizeof(t_ptree))))
	{
		node->type = NT_FILENAME;
		if (!(node->content.cmd_name = ft_memalloc(sizeof(t_filename))))
			del_node(node);
	}
	return (node);
}

t_ptree			*filename(t_parser *p)
{
	t_list	*head;
	t_ptree	*node;

	head = p->tlst;
	node = NULL;
	if (((t_token *)head->content)->type == T_WORD)
	{
		if (!(node = filename_new()))
			return (NULL);
		node->content.cmd_name->data =
			ft_strdup(((t_token *)head->content)->data);
		p->tlst = head->next;
	}
	return (node);
}
