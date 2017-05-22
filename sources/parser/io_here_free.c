/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_here_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:27:36 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 15:48:10 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			io_here_free(t_io_here *here)
{
	here_end_free(&here->here_end->content->here_end);
	free(here->here_end->content);
	free(here->here_end);
}
