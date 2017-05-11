/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:35:41 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/06 10:49:25 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	i;

	dlen = 0;
	while (dst[dlen] != '\0' && dlen < size)
		dlen++;
	i = 0;
	if (size - dlen)
	{
		while (src[i] != '\0' && i < size - dlen - 1)
		{
			dst[dlen + i] = src[i];
			i += 1;
		}
		dst[dlen + i] = 0;
	}
	return (dlen + ft_strlen(src));
}
