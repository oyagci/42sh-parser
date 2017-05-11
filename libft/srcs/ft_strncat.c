/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:21:03 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/05 11:50:10 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = s1;
	s = (char *)s2;
	while (*d)
		d += 1;
	i = 0;
	while (*s && i++ < n)
		*d++ = *s++;
	*d = '\0';
	return (s1);
}
