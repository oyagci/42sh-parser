/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:20:19 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 16:29:00 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

t_ptree			*complete_commands(t_parser *p)
{
	while (1)
	{
		if (!(node = newline_list(p)))
			break ;
		if (!(node = complete_command))
	}
	return (NULL);
}
