/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_setvalue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:53:49 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/11 16:00:05 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>
#include <libft.h>
#include <stdlib.h>

void			environ_setvalue(char *name, char *val)
{
	t_environ_var	*var;

	var = environ_getvar(name);
	if (var)
	{
		if (ft_strlen(var->value) >= ft_strlen(val))
			ft_strcpy(var->value, val);
		else
		{
			free(var->value);
			var->value = ft_strdup(val);
		}
	}
	else
	{
		var = ft_memalloc(sizeof(t_environ_var));
		var->name = ft_strdup(name);
		var->value = ft_strdup(val);
		environ_add_var(var);
	}
}
