/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_enter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:03:16 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 15:45:19 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_enter(const unsigned char *const buffer)
{
	char const	arrow[] = { 10, 0, 0, 0, 0, 0, 0, 0 };

	if (ft_memcmp(arrow, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
