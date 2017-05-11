/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_alt_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:26:57 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 11:32:28 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_alt_c(const unsigned char *const buffer)
{
	unsigned char const	alt_c[] = { 195, 167, 0, 0, 0, 0, 0, 0 };

	if (ft_memcmp(alt_c, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
