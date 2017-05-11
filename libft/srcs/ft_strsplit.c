/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:25:14 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/04 10:25:16 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

unsigned int	nb_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb;

	nb = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (i > 0 ? (s[i - 1] == c) : 1))
			nb += 1;
		i += 1;
	}
	return (nb);
}

char			*dup_word(char const *s, char c)
{
	char	*word;
	int		size;

	word = NULL;
	size = 0;
	while (s[size] != c && s[size] != 0)
		size += 1;
	word = ft_strnew(size);
	ft_strlcat(word, s, size + 1);
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**split;
	unsigned int	i;
	unsigned int	j;

	if (!(split = (char **)ft_memalloc(sizeof(char *) * (nb_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (i > 0 ? (s[i - 1] == c) : 1))
			split[j++] = dup_word(&s[i++], c);
		else
			i += 1;
	}
	return (split);
}
