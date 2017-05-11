/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_alt_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:38:40 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 16:16:26 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_alt_w(const unsigned char *const buffer)
{
	char const	alt_w[] = { 226, 136, 145, 0, 0, 0, 0, 0 };

	if (ft_memcmp(alt_w, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
