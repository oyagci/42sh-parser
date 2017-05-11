/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:44:23 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/28 13:12:18 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>
#include <libft.h>

char			*get_current_word_start(t_line *line)
{
	size_t	i;

	i = line->index;
	while (i > 0 && !ft_isspace(*(line->content + i)))
		i -= 1;
	return (line->content + i);
}

size_t			get_current_word_len(t_line *line)
{
	size_t	i;

	i = 0;
	while (!ft_isspace(*(line->content + line->index + i)) &&
			*(line->content + line->index + i))
		i += 1;
	return (i);
}

char			*get_current_word(t_line *line)
{
	size_t	len;
	char	*start;
	char	*word;

	len = 0;
	start = get_current_word_start(line);
	len = get_current_word_len(line);
	word = ft_strndup(start, len);
	return (word);
}
