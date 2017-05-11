/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:08:04 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/05 15:31:28 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *substring;

	if (!s)
		return (NULL);
	if (!(substring = ft_strnew(len)))
		return (NULL);
	ft_strncpy(substring, &s[start], len + 1);
	substring[len] = 0;
	return (substring);
}
