/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_getvar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:54:47 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/27 14:58:26 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>

t_environ_var	*environ_getvar(char *name)
{
	t_list			*environ;
	t_environ_var	*cur;

	environ = environ_get();
	while (environ)
	{
		cur = environ->content;
		if (ft_strequ(cur->name, name))
			return (environ->content);
		environ = environ->next;
	}
	return (NULL);
}
