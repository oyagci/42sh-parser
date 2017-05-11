/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_ctrl_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:59:17 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 14:59:27 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_ctrl_d(const char *const buffer)
{
	char const	arrow[] = { 4, 0, 0, 0, 0, 0, 0, 0 };

	if (ft_memcmp(arrow, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
