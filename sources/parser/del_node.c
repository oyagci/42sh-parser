/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:19:38 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/17 12:33:04 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			del_node(t_ptree *node)
{
	if (node->type == NT_FILENAME)
		del_filename(node->content.filename);
	else if (node->type == NT_IO_FILE)
		del_io_file(node->content.io_file);
	else if (node->type == NT_IO_REDIRECT)
		del_io_redirect(node->content.io_redirect);
	else if (node->type == NT_COMPLETE_COMMAND)
		complete_command_del(node->content.cpcmd);
	free(node);
}
