/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:31:58 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 14:46:36 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

void			complete_command_free(union u_node *content)
{
	(void)content;
	/*
	t_complete_command	*cmd;

	cmd = &content->cpcmd;
	ptree_free(&cmd->list);
	*/
}
