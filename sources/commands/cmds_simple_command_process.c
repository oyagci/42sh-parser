/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_simple_command_process.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:42:48 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/31 15:03:25 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>

t_list		*get_spcmd_suffixes(t_ptree *suffixes)
{
	t_list	*lst;
	t_list	*head;
	t_list	*elem;

	lst = NULL;
	elem = NULL;
	if (suffixes)
	{
		head = suffixes->content->cmd_suffix.words;
		while (head)
		{
			elem = ft_lstnew(NULL, 0);
			elem->content = ft_strdup(head->content);
			ft_lstpush(&lst, elem);
			head = head->next;
		}
	}
	return (lst);
}

char		**get_spcmd_av(t_spcommand *spcmd)
{
	t_list	*avlst;
	t_list	*elem;

	avlst = NULL;
	if (spcmd->name)
	{
		elem = ft_lstnew(NULL, 0);
		elem->content = ft_strdup(spcmd->name->content->cmd_name.data);
		ft_lstpush(&avlst, elem);
	}
	if ((elem = get_spcmd_suffixes(spcmd->suffix)))
		ft_lstpush(&avlst, elem);
	return (ft_lststr(avlst));
}

t_process	*cmds_simple_command_get_process(t_ptree *spcmd)
{
	t_process	*p;

	if ((p = ft_memalloc(sizeof(t_process))))
	{
		p->argv = get_spcmd_av(&spcmd->content->sp_command);
	}
	return (p);
}
