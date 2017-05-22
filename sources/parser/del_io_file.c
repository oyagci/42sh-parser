/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_io_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:32:14 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 15:33:06 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void				del_io_file(t_io_file *iofile)
{
	del_node(iofile->filename);
	free(iofile);
}
