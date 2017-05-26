/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sequence_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:54:58 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 14:03:29 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			pipe_sequence_free(union u_node *content)
{
	t_pipe_sequence	*sequence;
	t_list			*next;

	sequence = &content->pipe_sequence;
	while (sequence->commands)
	{
		next = sequence->commands->next;
		ptree_free((t_ptree **)&sequence->commands->content);
		free(sequence->commands);
		sequence->commands = next;
	}
}
