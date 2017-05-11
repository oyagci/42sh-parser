/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:47:53 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/08 09:42:13 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!len)
		return (dst);
	len--;
	d = dst;
	s = (unsigned char *)src;
	if (src == dst)
		return (dst);
	else if (src < dst)
	{
		s = (unsigned char *)src + len;
		d = dst + len;
		while (len--)
			*d-- = *s--;
		*d = *s;
	}
	else if (dst < src)
	{
		while (len--)
			*d++ = *s++;
		*d = *s;
	}
	return (dst);
}
