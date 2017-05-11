/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_ctrl_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:34:43 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/29 11:02:40 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_ctrl_f(const char *const buffer)
{
	char const	ctrl_f[] = { 27, 70, 0, 0, 0, 0, 0, 0 };

	if (ft_memcmp(ctrl_f, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
