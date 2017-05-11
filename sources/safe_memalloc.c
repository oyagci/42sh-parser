/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_memalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:03:26 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/05 13:04:22 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*safe_memalloc(size_t size)
{
	void *mem;

	mem = ft_memalloc(size);
	if (mem == NULL)
		exit(EXIT_FAILURE);
	return (mem);
}
