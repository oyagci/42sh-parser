/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_goto_begin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 10:50:46 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 10:51:36 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>

void			line_goto_begin(t_line *line)
{
	line->index = 0;
}
