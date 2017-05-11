/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_autocomplete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:31:31 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/28 13:11:09 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>
#include <libft.h>

void			line_autocomplete(t_line *line)
{
	char	*cur_word;

	cur_word = get_current_word(line);
	if (find_command(cur_word))
		;
	ft_strdel(&cur_word);
}
