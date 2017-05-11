/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_backspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:58:48 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 14:59:05 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_backspace(const char *const buffer)
{
	char const	back_sp[] = { 127, 0, 0, 0, 0, 0, 0, 0 };

	if (ft_memcmp(back_sp, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
