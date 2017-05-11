/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:59:48 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 15:00:15 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_delete(const char *const buffer)
{
	char const	arrow[] = { 27, 91, 51, 126, 0, 0, 0, 0 };

	if (ft_memcmp(arrow, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
