/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_get_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:14:46 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/26 13:20:20 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <environ/environ.h>

static char		*get_name_and_value(t_environ_var *var)
{
	char	*name_val;

	name_val = ft_strnew(ft_strlen(var->name) + ft_strlen(var->value) + 1);
	ft_strcat(name_val, var->name);
	ft_strcat(name_val, "=");
	ft_strcat(name_val, var->value);
	return (name_val);
}

char			**environ_get_str_custom(t_list *env)
{
	char	**environ;
	size_t	sz;
	size_t	i;

	sz = ft_lstcount(env);
	environ = (char **)ft_memalloc(sizeof(char *) * (sz + 1));
	i = 0;
	while (i < sz)
	{
		environ[i] = get_name_and_value(env->content);
		env = env->next;
		i += 1;
	}
	return (environ);
}

char			**environ_get_str(void)
{
	return (environ_get_str_custom(environ_get()));
}
