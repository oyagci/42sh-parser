/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 12:50:45 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/07 17:04:25 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commands/commands.h>
#include <shell/builtins/builtins.h>

int			is_builtin(char *name)
{
	char	*builtins[] = { "cd", "env", "setenv", "unsetenv", NULL };
	size_t	i;

	i = 0;
	while (builtins[i])
	{
		if (ft_strequ(name, builtins[i]))
			return (1);
		i += 1;
	}
	return (0);
}

int			(*get_builtin(char *name))(char **)
{
	char	*builtins_str[] = { "cd", "env", "setenv", "unsetenv", NULL };
	int		(*builtins[])(char **) = { builtin_cd, builtin_env,
		builtin_setenv, builtin_unsetenv };
	size_t	i;

	i = 0;
	while (builtins_str[i])
	{
		if (ft_strequ(name, builtins_str[i]))
			return (builtins[i]);
		i += 1;
	}
	return (NULL);
}

int			run_builtin(char **argv)
{
	int		(*f)(char **);

	if ((f = get_builtin(argv[0])))
	{
		f(argv);
		return (1);
	}
	return (0);
}
