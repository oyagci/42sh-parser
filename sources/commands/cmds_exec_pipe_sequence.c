/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_exec_pipe_sequence.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:54:35 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/31 16:19:24 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>

char			**get_termcommand_av(t_ptree *cmd)
{
	(void)cmd;
	return (NULL);
}

t_termcommand	*get_termcommands(t_list *cmdlst)
{
	size_t			count;
	size_t			i;
	t_termcommand	*cmds;

	count = ft_lstcount(cmdlst);
	cmds = ft_memalloc(sizeof(t_termcommand));
	i = 0;
	while (i < count)
	{
		cmds[i].av = get_termcommand_av(cmdlst->content);
		i += 1;
	}
	return (NULL);
}

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
