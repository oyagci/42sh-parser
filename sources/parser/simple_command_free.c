/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:24:11 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 13:02:27 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			simple_command_free(union u_node *node)
{
	t_spcommand *sp;

	sp = &node->sp_command;
	if (sp == (void *)ERR_SYNTAX)
		return ;
	sp->prefix != (void *)ERR_SYNTAX ? ptree_free(&sp->prefix) : 0;
	sp->suffix != (void *)ERR_SYNTAX ? ptree_free(&sp->suffix) : 0;
	sp->name != (void *)ERR_SYNTAX ? ptree_free(&sp->name) : 0;
	sp->word != (void *)ERR_SYNTAX ? ptree_free(&sp->word) : 0;
}
