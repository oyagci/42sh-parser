/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:58:43 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 16:17:54 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>
#include <stdlib.h>
#include <libft.h>

void			line_init(t_line *line)
{
	ft_bzero(line, sizeof(*line));
	line->content = ft_strnew(255);
	line->max_len = 255;
}
