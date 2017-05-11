/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:05:07 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 15:43:07 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_down(const unsigned char *const buffer)
{
	char const	arrow[] = { 27, 91, 66, 0, 0, 0, 0, 0 };

	if (ft_memcmp(arrow, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
