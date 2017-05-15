/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:15:29 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 16:43:17 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

t_ptree			*program(t_parser *p)
{
	t_ptree	*node;

	while ((node = linebreak(p)))
		del_node(node);
	node = complete_commands(p);
	while (node = linebreak(p))
		del_node(linebreak);
}
