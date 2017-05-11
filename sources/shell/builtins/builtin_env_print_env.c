/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_print_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:18:32 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/19 14:04:47 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <shell/builtins/builtin_env.h>
#include <environ/environ.h>
#include <stdlib.h>

void			env_add_assignments(t_list *assignments, t_list **env)
{
	t_list			*elem;
	t_environ_var	*var;

	elem = NULL;
	(void)env;
	(void)var;
	while (assignments)
	{
		var = ft_memalloc(sizeof(t_environ_var));
		elem = ft_lstnew(NULL, 0);
		elem->content = var;
		var->name = ft_strdup(((t_environ_var *)assignments->content)->name);
		var->value = ft_strdup(((t_environ_var *)assignments->content)->value);
		ft_lstpush(env, elem);
		assignments = assignments->next;
	}
}

t_list			*get_custom_env(int empty_env, t_list *assignments)
{
	t_list	*env;

	env = (empty_env ? NULL : environ_dup());
	(void)assignments;
	env_add_assignments(assignments, &env);
	return (env);
}

void			del_env(void *content, size_t content_size)
{
	t_environ_var *var;

	(void)content_size;
	var = content;
	free(var->name);
	free(var->value);
	free(var);
}

void			print_env(t_list *assignments, int empty_env)
{
	t_list	*env;
	t_list	*head;

	env = get_custom_env(empty_env, assignments);
	head = env;
	while (env)
	{
		ft_putstr(((t_environ_var *)env->content)->name);
		ft_putstr("=");
		ft_putendl(((t_environ_var *)env->content)->value);
		env = env->next;
	}
	ft_lstdel(&head, del_env);
}
