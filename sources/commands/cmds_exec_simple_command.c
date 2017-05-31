/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_exec_simple_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:12:38 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/31 15:48:16 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>

int			cmds_exec_simple_command(t_ptree *spcommand)
{
	char	**av;

	av = get_spcmd_av(&spcommand->content->sp_command);
	while (*av)
	{
		ft_putstr(*av);
		ft_putchar(*(av + 1) ? ' ' : '\n');
		av += 1;
	}
	return (0);
}
