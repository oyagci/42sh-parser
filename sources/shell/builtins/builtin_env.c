/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:52:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/26 13:46:34 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>
#include <shell/builtins/builtin_env.h>
#include <libft.h>
#include <shell/shell.h>
#include <string.h>
#include <stdio.h>

static void		usage(void)
{
	ft_putendl("usage: env [-i] [name=value ...] [utility [argument ...]]");
}

t_environ_var	*get_environ_var(char *s)
{
	t_environ_var	*assign;
	char			*delim;

	assign = NULL;
	if ((delim = ft_strchr(s, '=')) != NULL)
	{
		assign = ft_memalloc(sizeof(t_environ_var));
		assign->name = ft_strndup(s, delim - s);
		assign->value = ft_strdup(delim + 1);
	}
	return (assign);
}

int				get_environ_vars(t_list **assignments, int ac, char *av[])
{
	int				i;
	t_environ_var	*new_assign;
	t_list			*elem;

	*assignments = 0;
	i = 0;
	(void)elem;
	while (i < ac && (new_assign = get_environ_var(av[i])))
	{
		elem = ft_lstnew(NULL, 0);
		elem->content = new_assign;
		ft_lstpush(assignments, elem);
		i += 1;
	}
	return (i);
}

int				env(int argc, char *argv[])
{
	t_list	*assignments;
	int		empty_env;

	argv += 1;
	argc -= 1;
	empty_env = 0;
	if (argc > 0 && ft_strcmp(argv[0], "-i") == 0)
	{
		empty_env = 1;
		argv += 1;
		argc -= 1;
	}
	argv += get_environ_vars(&assignments, argc, argv);
	if (*argv)
		env_cmd(assignments, argv, empty_env);
	else
		print_env(assignments, empty_env);
	ft_lstdel(&assignments, del_env);
	return (0);
}

int				builtin_env(char **av)
{
	size_t	argc;

	if ((argc = arg_count(av)) == 0)
	{
		usage();
		return (1);
	}
	return (env(argc, av));
}
