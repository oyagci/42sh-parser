/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:56:19 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/29 14:44:26 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>
#include <parser/parser.h>

int			cmds_exec(t_ptree *lists)
{
	t_list	*head;

	head = lists->content->list.andlst;
	while (head)
	{
		cmds_exec_and_or(head->content);
		head = head->next;
	}
	return (0);
}
