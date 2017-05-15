/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:59:13 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 14:08:46 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>

t_list		*get_tlst(void)
{
	t_token	*a;
	t_token *b;

	t_list	*lst;

	a = ft_memalloc(sizeof(t_token));
	a->data = ft_strdup("ls");
	a->type = T_WORD;

	b = ft_memalloc(sizeof(t_token));
	b->data = NULL;
	b->type = T_END;

	lst = ft_lstnew(a, sizeof(*a));
	ft_lstpush(&lst, ft_lstnew(b, sizeof(*b)));

	return (lst);
}

#include <stdio.h>
int			main(void)
{
	t_parser p;

	p.ptree = ptree_init();
	p.tlst = get_tlst();

	t_ptree *cmd = cmd_name(&p);

	if (cmd)
	{
		if (cmd->type == NT_CMD_NAME)
		{
			printf("[NT_CMD_NAME] -> ");
			printf("%s", cmd->content.cmd_name->data);
		}
		printf("\n");
	}
}
