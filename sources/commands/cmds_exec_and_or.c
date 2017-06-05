/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_exec_and_or.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:18:30 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 15:03:58 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>
#include <parser/parser.h>

int				cmds_exec_and_or(t_ptree *andor)
{
	t_list	*andlst;
	int		ret;

	andlst = andor->content->and_or.pipelines;
	ret = cmds_exec_pipeline((t_ptree *)andlst->content);
	andlst = andlst->next;
	while (andlst)
	{
		if (((t_ptree *)andlst->content)->content->pipeline.type ==
				PL_AND_IF && ret == 0)
			ret = cmds_exec_pipeline((t_ptree *)andlst->content);
		else if (((t_ptree *)andlst->content)->content->pipeline.type ==
				PL_OR_IF && ret != 0)
			ret = cmds_exec_pipeline((t_ptree *)andlst->content);
		else
			break ;
		andlst = andlst->next;
	}
	return (ret);
}
