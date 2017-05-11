/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 08:45:57 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/06 09:02:36 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

static size_t	get_trimed_len(const char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = len - 1;
	while (is_space(str[i]) && i >= 0)
	{
		len -= 1;
		i -= 1;
	}
	i = 0;
	while (is_space(str[i]) && str[i] != '\0')
	{
		len -= 1;
		i += 1;
	}
	if (len <= 0)
		return (0);
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*clean_str;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = get_trimed_len(s);
	if (!(clean_str = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (is_space(s[i]) && s[i] != '\0')
		i += 1;
	ft_strncpy(clean_str, &s[i], len);
	clean_str[len] = '\0';
	return (clean_str);
}
