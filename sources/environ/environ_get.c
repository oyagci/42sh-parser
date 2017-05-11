/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:18:09 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/10 14:23:01 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>

extern t_list	*g_environ;

t_list			*environ_get(void)
{
	if (!g_environ)
		environ_load();
	return (g_environ);
}
