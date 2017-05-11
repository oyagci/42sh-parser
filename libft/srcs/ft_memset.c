/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:18:48 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/05 09:10:17 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	u_c;
	unsigned char	*u_b;

	u_c = (unsigned char)c;
	u_b = (unsigned char *)b;
	while (len--)
		*u_b++ = u_c;
	return (b);
}
