/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_next_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:47:27 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/27 11:28:47 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>
#include <libft.h>

void			line_next_word(t_line *line)
{
	while (*(line->content + line->index) &&
			ft_isalnum(*(line->content + line->index)))
		line->index += 1;
	while (*(line->content + line->index) &&
			!ft_isalnum(*(line->content + line->index)))
		line->index += 1;
}
