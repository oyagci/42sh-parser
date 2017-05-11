/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:36:56 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 13:08:00 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <getline/getline.h>

int				line_delchar(t_line *l)
{
	ft_memmove(l->content + l->index - 1, l->content + l->index,
			ft_strlen(l->content + l->index) + 1);
	l->index -= 1;
	l->len -= 1;
	return (0);
}
