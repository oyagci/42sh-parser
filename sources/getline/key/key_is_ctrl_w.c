/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_ctrl_w.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:29:26 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 16:30:11 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_ctrl_w(const unsigned char *const buffer)
{
	char const	ctrl_w[] = { 23, 0, 0, 0, 0, 0, 0, 0 };

	if (ft_memcmp(ctrl_w, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
