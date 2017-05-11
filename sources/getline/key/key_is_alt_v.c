/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_alt_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:28:29 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 11:29:36 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_alt_v(const unsigned char *const buffer)
{
	char const	alt_v[] = { 226, 136, 154, 0, 0, 0, 0, 0 };

	if (ft_memcmp(alt_v, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
