/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_page_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:05:03 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 15:36:07 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_page_down(const unsigned char *const buffer)
{
	unsigned char const	key[] = { 27, 91, 54, 126, 0, 0, 0, 0 };

	if (ft_memcmp(key, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
