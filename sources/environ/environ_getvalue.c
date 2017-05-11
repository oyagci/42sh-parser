/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_getvalue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:05:56 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/27 15:08:09 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>

/*
** environ_getvalue: Get the value of a variable of the env.
** The returned value should not be freed.
*/

char			*environ_getvalue(char *name)
{
	t_list			*environ;
	t_environ_var	*cur;

	environ = environ_get();
	while (environ)
	{
		cur = environ->content;
		if (ft_strequ(cur->name, name))
			return (cur->value);
		environ = environ->next;
	}
	return (NULL);
}
