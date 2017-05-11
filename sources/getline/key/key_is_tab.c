/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:30:16 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/27 16:34:02 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_tab(const unsigned char *const buffer)
{
	unsigned char const	key[] = { 9, 0, 0, 0, 0, 0, 0, 0 };

	if (ft_memcmp(key, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
