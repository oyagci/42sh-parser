/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_ctrl_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:41:10 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 15:42:54 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_ctrl_a(const char *const buffer)
{
	char const	ctrl_b[] = { 1, 0, 0, 0, 0, 0, 0, 0 };

	if (ft_memcmp(ctrl_b, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
