/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:03:50 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 15:44:32 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_left(const unsigned char *const buffer)
{
	char const	arrow[] = { 27, 91, 68, 0, 0, 0, 0, 0 };

	if (ft_memcmp(arrow, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
