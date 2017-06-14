/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_exec_pipe_sequence.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:54:35 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/01 14:06:58 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>

void			append_process(t_process **p, t_process *new)
{
	t_process *head;

	if ((head = *p) != NULL)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
		*p = new;
}

t_process		*cmds_exec_pipe_sequence(t_ptree *pseq)
{
	t_list		*head;
	t_ptree		*node;
	t_process	*processes;

	processes = NULL;
	head = pseq->content->pipe_sequence.commands;
	while (head)
	{
		node = (t_ptree *)head->content;
		append_process(&processes, cmds_exec_command(node));
		head = head->next;
	}
	return (processes);
}
