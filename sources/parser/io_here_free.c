/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_here_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:27:36 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 13:16:09 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			io_here_free(union u_node *content)
{
	t_io_here *here;

	here = &content->io_here;
	if (here->here_end)
	{
		here_end_free(here->here_end->content);
		free(here->here_end->content);
		free(here->here_end);
	}
}
