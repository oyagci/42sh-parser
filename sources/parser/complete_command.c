/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:29:06 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 16:32:55 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

t_ptree			*complete_command(t_parser *p)
{
	t_ptree		*node;

	if (!(node = list(p)))
		return (NULL);
	if (p->tlst->content->type = T_SEMICOL)
		p->tlst = p->tlst->next;
	return (node);
}
