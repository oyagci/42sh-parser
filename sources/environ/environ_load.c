/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:20:39 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 15:18:34 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errors/errors.h>
#include <environ/environ.h>
#include <libft.h>

t_list			*g_environ;

static char		*get_envvar_name(char *environ)
{
	char	*name;
	char	*limit;

	if ((limit = ft_strchr(environ, '=')) == NULL)
		return (NULL);
	name = ft_strndup(environ, limit - environ);
	return (name);
}

static char		*get_envvar_value(char *environ)
{
	char	*value;
	char	*limit;

	if ((limit = ft_strchr(environ, '=')) == NULL)
		return (NULL);
	value = ft_strndup(limit + 1, ft_strlen(limit + 1));
	return (value);
}

static int		environ_dup_var(char *environ)
{
	t_environ_var	*new_var;

	if (!(new_var = ft_memalloc(sizeof(t_environ_var))))
		return (-1);
	if ((new_var->name = get_envvar_name(environ)) != NULL)
	{
		if ((new_var->value = get_envvar_value(environ)) == NULL)
			return (-1);
		if (environ_add_var(new_var) == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int				environ_load(void)
{
	extern char	**environ;
	size_t		i;

	i = 0;
	while (environ[i] != 0)
	{
		if (environ_dup_var(environ[i]) == -1)
			return (-1);
		i += 1;
	}
	return (0);
}
