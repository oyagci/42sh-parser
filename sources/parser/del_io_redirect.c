/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_io_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:46:43 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/15 15:48:00 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			del_io_redirect(t_io_redirect *io_redirect)
{
	del_node(io_redirect->io_file);
	free(io_redirect);
}
