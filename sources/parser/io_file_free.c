/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:42:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 13:18:28 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			io_file_free(union u_node *node)
{
	t_io_file	*f;

	f = &node->io_file;
	if (f->filename)
	{
		filename_free(f->filename->content);
		free(f->filename->content);
		free(f->filename);
	}
}
