/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linehist_reset_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:37:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/26 17:38:37 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

extern size_t	g_current_index;

void			linehist_reset_index(void)
{
	g_current_index = 0;
}
