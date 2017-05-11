/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:05:26 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 15:42:40 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_up(const unsigned char *const buffer)
{
	char const	arrow[] = { 27, 91, 65, 0, 0, 0, 0, 0 };

	if (ft_memcmp(arrow, buffer, ft_strlen(arrow)) == 0)
		return (TRUE);
	return (FALSE);
}
