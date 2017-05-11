/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_ctrl_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:31:01 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 15:42:08 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_ctrl_b(const char *const buffer)
{
	char const	ctrl_b[] = { 27, 66, 0, 0, 0, 0, 0, 0 };

	if (ft_memcmp(ctrl_b, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
