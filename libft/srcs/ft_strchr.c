/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:33:27 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/05 11:56:22 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = '\0';
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i += 1;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}
