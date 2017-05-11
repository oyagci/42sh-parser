/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:39:39 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/05 11:37:46 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcat(char *dst, const char *src)
{
	char	*d;
	char	*s;

	d = dst;
	s = (char *)src;
	while (*d)
		d += 1;
	while (*s)
		*d++ = *s++;
	*d = '\0';
	return (dst);
}
