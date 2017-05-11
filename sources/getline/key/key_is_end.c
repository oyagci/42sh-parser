/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 10:47:49 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 10:56:29 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_end(const char *const buffer)
{
	char const	end[] = { 27, 91, 70, 0, 0, 0, 0, 0 };

	if (ft_memcmp(end, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
