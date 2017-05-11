/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_del_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:07:24 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/27 11:31:20 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>
#include <libft.h>

void			line_del_word(t_line *l)
{
	size_t	i;

	i = 0;
	while (ft_isspace(*(l->content + l->index - 1)) && l->index > 0)
	{
		l->index -= 1;
		i += 1;
	}
	while (!(ft_isspace(*(l->content + l->index - 1))) && l->index > 0)
	{
		l->index -= 1;
		i += 1;
	}
	l->len -= i;
	ft_memmove(l->content + l->index, l->content + l->index + i,
			ft_strlen(l->content + l->index + i) + 1);
}
