/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:40:40 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/27 11:27:41 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>
#include <unistd.h>

void			line_down(t_line *line)
{
	size_t	line_sz;
	size_t	old_x;
	size_t	old_y;

	line_sz = line_size() - 2;
	old_y = line->index / line_sz;
	old_x = line->index % line_sz;
	while (line->index / line_sz <= old_y && line->index < line->len)
		line->index += 1;
	while (line->index % line_sz <= old_x && line->index < line->len)
		line->index += 1;
}
