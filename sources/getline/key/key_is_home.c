/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_home.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 10:39:07 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/25 10:46:52 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				key_is_home(const char *const buffer)
{
	char const	home[] = { 27, 91, 72, 0, 0, 0, 0, 0 };

	if (ft_memcmp(home, buffer, 8) == 0)
		return (TRUE);
	return (FALSE);
}
