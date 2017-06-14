/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:04:49 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 14:05:59 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

void			command_free(union u_node *content)
{
	ptree_free((t_ptree **)&content->command.cmd);
	ptree_free((t_ptree **)&content->command.redirect);
}
