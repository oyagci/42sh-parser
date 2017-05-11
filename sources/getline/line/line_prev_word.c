/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_prev_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:59:17 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/27 11:28:17 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>
#include <libft.h>

void			line_prev_word(t_line *line)
{
	if (*(line->content + line->index) != 0)
	{
		while (!ft_isalnum(*(line->content + line->index)) && line->index > 0)
			line->index -= 1;
	}
	if (line->index > 0)
	{
		line->index -= 1;
		if (line->index > 0)
			while (ft_isalnum(*(line->content + line->index - 1)) &&
					line->index - 1 > 0)
				line->index -= 1;
		if (line->index == 1 && ft_isalnum(*(line->content + line->index)))
			line->index -= 1;
	}
}
