/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_ctrl_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:41:32 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 15:43:04 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_ctrl_e(const char *const buffer)
{
	char const	ctrl_b[] = { 5, 0, 0, 0, 0, 0, 0, 0 };

	if (ft_memcmp(ctrl_b, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
