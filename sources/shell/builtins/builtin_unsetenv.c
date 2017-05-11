/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:53:57 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/14 14:02:47 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <environ/environ.h>
#include <shell/shell.h>

int				builtin_unsetenv(char **av)
{
	size_t	ac;

	ac = arg_count(av);
	if (ac > 1)
		environ_remove(av[1]);
	return (0);
}
