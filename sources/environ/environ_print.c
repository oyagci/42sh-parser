/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:09:25 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 15:10:44 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>

void			environ_print(void)
{
	t_environ_var	*cur_var;
	t_list			*env;

	env = environ_get();
	while (env)
	{
		cur_var = env->content;
		ft_putstr(cur_var->name);
		ft_putstr("=");
		ft_putendl(cur_var->value);
		env = env->next;
	}
}
