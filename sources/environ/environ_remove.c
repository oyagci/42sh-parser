/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 13:53:10 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/24 13:10:01 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>
#include <stdlib.h>
#include <stdlib.h>

static void		clean_up(t_list **env)
{
	t_list	*head;
	t_list	*tmp;

	head = *env;
	if (*env && (*env)->content == NULL)
	{
		head = (*env)->next;
		free(*env);
	}
	while (*env && (*env)->next)
	{
		if ((*env)->next->content == NULL)
		{
			tmp = (*env)->next->next;
			free((*env)->next);
			(*env)->next = tmp;
		}
		*env = (*env)->next;
	}
	*env = head;
}

int				environ_remove(char *name)
{
	t_list			*env;
	t_environ_var	*var;
	extern t_list	*g_environ;

	env = g_environ;
	while (env)
	{
		var = env->content;
		if (ft_strequ(var->name, name))
		{
			ft_strdel(&var->name);
			ft_strdel(&var->value);
			free(var);
			env->content = NULL;
		}
		env = env->next;
	}
	clean_up(&g_environ);
	return (0);
}
