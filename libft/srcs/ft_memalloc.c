/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:08:52 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/03 12:59:01 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	if (!(mem = (void *)malloc(sizeof(char) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)mem)[i] = 0;
		i += 1;
	}
	return (mem);
}
