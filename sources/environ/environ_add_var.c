/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_add_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:18:08 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/27 11:20:22 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>

extern t_list	*g_environ;

int				environ_add_var(t_environ_var *var)
{
	t_list	*elem;

	if ((elem = ft_lstnew(NULL, 0)) == NULL)
		return (-1);
	elem->content = var;
	elem->content_size = sizeof(*var);
	ft_lstpush(&g_environ, elem);
	return (0);
}
