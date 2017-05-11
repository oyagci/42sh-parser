/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:58:49 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/19 14:05:55 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>

t_environ_var	*environ_dup_var(t_environ_var *original)
{
	t_environ_var	*dup;

	dup = ft_memalloc(sizeof(t_environ_var));
	dup->name = ft_strdup(original->name);
	dup->value = ft_strdup(original->value);
	return (dup);
}

t_list			*environ_dup(void)
{
	t_list			*environ;
	t_list			*dup;
	t_list			*elem;
	t_environ_var	*var;

	dup = NULL;
	environ = environ_get();
	while (environ)
	{
		var = environ_dup_var(environ->content);
		elem = ft_lstnew(NULL, 0);
		elem->content = var;
		ft_lstpush(&dup, elem);
		environ = environ->next;
	}
	return (dup);
}
