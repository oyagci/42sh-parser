/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_exec_and_or.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:18:30 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/31 16:57:32 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>
#include <parser/parser.h>

int				cmds_exec_and_or(t_ptree *andor)
{
	t_list	*andlst;
	int		ret;

	andlst = andor->content->and_or.pipelines;
	while (andlst)
	{
		ret = cmds_exec_pipeline((t_ptree *)andlst->content);
		if ((andlst = andlst->next) != NULL)
		{
			if (((t_ptree *)andlst->content)->content->pipeline.type == PL_AND_IF)
			{
				if (ret == 0)
					ret = cmds_exec_pipeline((t_ptree *)andlst->content);
				else
					break ;
			}
			else if (((t_ptree *)andlst->content)->content->pipeline.type == PL_OR_IF)
			{
				if (ret != 0)
					ret = cmds_exec_pipeline((t_ptree *)andlst->content);
				else
					break ;
			}
			andlst = andlst->next;
		}
	}
	return (ret);
}
