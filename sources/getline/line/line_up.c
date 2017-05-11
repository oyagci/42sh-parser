/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:12:33 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/27 11:27:07 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>

void			line_up(t_line *line)
{
	size_t	line_sz;
	size_t	old_x;
	size_t	old_y;

	line_sz = line_size() - 2;
	old_y = line->index / line_sz;
	old_x = line->index % line_sz;
	if (old_y > 0)
	{
		while (line->index / line_sz >= old_y && line->index > 0)
			line->index -= 1;
		while (line->index % line_sz >= old_x && line->index > 0)
			line->index -= 1;
	}
}
